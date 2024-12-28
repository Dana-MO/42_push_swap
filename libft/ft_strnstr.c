/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:34:51 by domar             #+#    #+#             */
/*   Updated: 2024/09/17 11:34:52 by domar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	e;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i] && i < len)
	{
		e = 0;
		while (big[i + e] && little[e]
			&& (i + e) < len && (big[i + e] == little[e]))
		{
			e++;
		}
		if (!little[e])
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
