/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:43:41 by domar             #+#    #+#             */
/*   Updated: 2024/11/18 11:19:07 by domar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ptrlen(unsigned long value)
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

void	ft_putptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	else
	{
		count += write(1, "0x", 2);
		ft_putptr(ptr);
		count += ft_ptrlen(ptr);
	}
	return (count);
}
