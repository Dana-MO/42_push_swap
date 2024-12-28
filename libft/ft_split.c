/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:35:48 by domar             #+#    #+#             */
/*   Updated: 2024/09/17 11:35:49 by domar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	bool	is_new_word;

	i = 0;
	while (*s)
	{
		is_new_word = false;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			if (!is_new_word)
			{
				i++;
				is_new_word = true;
			}
			s++;
		}
	}
	return (i);
}

static int	ft_arr_split(char **arr, char const *s, char c)
{
	size_t		i;
	const char	*word_start;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		word_start = s;
		while (*s && *s != c)
			++s;
		if ((s - word_start) > 0)
		{
			arr[i] = (char *)malloc(sizeof(char) * ((s - word_start) + 1));
			if (!arr[i])
			{
				while (i > 0)
					free(arr[--i]);
				return (-1);
			}
			ft_strlcpy(arr[i++], word_start, ((s - word_start) + 1));
		}
	}
	arr[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**arr;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	if (ft_arr_split(arr, s, c) == -1)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
