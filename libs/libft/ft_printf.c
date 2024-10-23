/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:07:01 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:11:46 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_option(va_list args, int c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (c == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_printp(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_printnbr((long)va_arg(args, int),
				10, "0123456789");
	else if (c == 'u')
		count += ft_printnbr((long)va_arg(args, unsigned int),
				10, "0123456789");
	else if (c == 'x')
		count += ft_printnbr((long)va_arg(args, unsigned int),
				16, "0123456789abcdef");
	else if (c == 'X')
		count += ft_printnbr((long)va_arg(args, unsigned int),
				16, "0123456789ABCDEF");
	else if (c == '%')
		count += ft_printchar(c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_option(args, *(++format));
		}
		else
			len += ft_printchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}
