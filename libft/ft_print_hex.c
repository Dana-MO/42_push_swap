/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:44:49 by domar             #+#    #+#             */
/*   Updated: 2024/10/01 11:38:01 by domar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hexlen(unsigned int value)
{
	size_t	len;

	len = 0;
	while (value)
	{
		len++;
		value = value / 16;
	}
	return (len);
}

void	ft_puthex(unsigned int num, char c)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, c);
		ft_puthex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (c == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
			else
				ft_putchar_fd((num - 10 + 'a'), 1);
		}
	}
}

int	ft_print_hex(unsigned int n, char c)
{
	int	count;

	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		ft_puthex(n, c);
		count += ft_hexlen(n);
	}
	return (count);
}
