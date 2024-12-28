/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:44:40 by domar             #+#    #+#             */
/*   Updated: 2024/11/18 11:19:28 by domar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(char specifier, va_list args)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (specifier == '%')
		len += ft_print_percent();
	else if (specifier == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long));
	else if (specifier == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), specifier);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_formats(*(++format), args);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}
