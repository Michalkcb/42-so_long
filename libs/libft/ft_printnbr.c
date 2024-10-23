/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:54:37 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:11:42 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(long n, int base, char *symbols)
{
	int		count;

	if (n < 0)
	{
		ft_printchar('-');
		return (ft_printnbr(-n, base, symbols) + 1);
	}
	else if (n < base)
		return (ft_printchar(symbols[n]));
	else
	{
		count = ft_printnbr(n / base, base, symbols);
		return (count + ft_printnbr(n % base, base, symbols));
	}
}
