/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:35:22 by domar             #+#    #+#             */
/*   Updated: 2024/09/17 11:35:25 by domar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	e;
	char	*str;

	i = 0;
	e = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[e] = s1[i];
		e++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[e] = s2[i];
		e++;
		i++;
	}
	str[e] = '\0';
	return (str);
}
