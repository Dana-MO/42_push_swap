/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:43:54 by domar             #+#    #+#             */
/*   Updated: 2024/10/01 12:12:56 by domar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_print_unsigned(n / 10);
	count += ft_print_char(n % 10 + '0');
	return (count);
}
