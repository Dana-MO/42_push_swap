/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:13:16 by domar             #+#    #+#             */
/*   Updated: 2024/10/27 12:19:47 by domar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 	
	read_line function 
	Reads data from the file descriptor (fd) into the buffer,
	then appends it to the static storage (storage).
*/

ssize_t	read_line(int fd, char *buffer, char **storage)
{
	ssize_t	file_r;
	char	*temp;

	file_r = read(fd, buffer, BUFFER_SIZE);
	if (!(*storage))
	{
		*storage = (char *)malloc(sizeof(char));
		if (*storage)
			(*storage)[0] = '\0';
	}
	if (*storage && file_r >= 0)
	{
		buffer[file_r] = '\0';
		temp = ft_strjoin(*storage, buffer);
		if (!temp)
			return (-1);
		free(*storage);
		*storage = temp;
	}
	else
		return (-1);
	return (file_r);
}

/*	
	get_next function;
	Extracts the next line from the static storage.
*/

char	*get_next(char **storage)
{
	char	*new_line;
	char	*temp;
	size_t	line_len;

	line_len = 0;
	new_line = NULL;
	if (ft_strchr(*storage, '\n'))
	{
		line_len = (ft_strchr(*storage, '\n')) - *storage + 1;
		new_line = ft_substr(*storage, 0, line_len);
		temp = ft_substr(*storage, line_len, (ft_strlen(*storage) - line_len));
		if (temp)
		{
			free(*storage);
			*storage = temp;
		}
	}
	if (!new_line && ft_strlen(*storage))
	{
		new_line = ft_substr(*storage, 0, ft_strlen(*storage));
		free(*storage);
		*storage = NULL;
	}
	return (new_line);
}

/*
	call_read function;
	Manages the reading process and ensures data is read
	until a newline character is found
	or end of file (EOF) is reached.
*/

ssize_t	call_read(int fd, char **storage)
{
	ssize_t	bytes_read;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	bytes_read = read_line(fd, buffer, storage);
	while (bytes_read > 0 && !(ft_strchr(*storage, '\n')))
		bytes_read = read_line(fd, buffer, storage);
	free(buffer);
	return (bytes_read);
}

/*
	get_next_line function;
	The main function to retrieve the next line from a file descriptor.
*/

char	*get_next_line(int fd)
{
	char			*result;
	static char		*storage;
	ssize_t			bytes_read;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = call_read(fd, &storage);
	if (bytes_read < 0 || !storage || storage[0] == '\0')
	{
		free(storage);
		storage = NULL;
		return (result);
	}
	result = get_next(&storage);
	if (!result)
	{
		free(storage);
		storage = NULL;
	}
	return (result);
}
