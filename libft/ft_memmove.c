/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:33:10 by domar             #+#    #+#             */
/*   Updated: 2024/09/17 14:40:14 by domar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*a;
	const unsigned char	*b;

	a = (unsigned char *) dst;
	b = (const unsigned char *) src;
	if ((!dst && !src) || len == 0)
		return (dst);
	if (a < b)
	{
		while (len--)
		{
			*a++ = *b++;
		}
	}
	else
	{
		while (len--)
		{
			a[len] = b[len];
		}
	}
	return (dst);
}
