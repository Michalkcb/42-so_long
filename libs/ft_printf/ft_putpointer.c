/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:00:01 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/03/12 21:54:49 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(uintptr_t x)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (x >= 16)
		len += print_hex(x / 16);
	len += ft_putchar(base[x % 16]);
	return (len);
}

int	ft_putpointer(void *ptr)
{
	int			len;
	uintptr_t	x;

	x = (uintptr_t)ptr;
	len = ft_putstr("0x");
	len += print_hex(x);
	return (len);
}
