/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:43:35 by domar             #+#    #+#             */
/*   Updated: 2024/10/01 11:38:29 by domar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int n)
{
	char	*s;
	size_t	len;

	len = 0;
	s = ft_itoa(n);
	if (!s)
		return (0);
	len = ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}
