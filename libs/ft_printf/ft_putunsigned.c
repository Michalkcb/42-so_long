/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:12:02 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/03/12 21:54:35 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	len;
	char			*base;

	len = 0;
	base = "0123456789";
	if (n >= 10)
		len += ft_putunsigned(n / 10);
	len += ft_putchar(base[n % 10]);
	return (len);
}
