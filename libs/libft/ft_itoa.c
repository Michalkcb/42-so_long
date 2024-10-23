/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:45:30 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:12:11 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n);

unsigned int	ft_ilen(int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str_num;
	unsigned int	len;
	unsigned int	num;

	num = n;
	len = ft_ilen(n);
	str_num = ft_calloc(len + 1, sizeof(char));
	if (!str_num)
		return (0);
	if (num == 0)
		*str_num = '0';
	*(str_num + len) = '\0';
	if (n < 0)
	{
		*str_num = '-';
		num = -n;
	}
	while (num != 0)
	{
		*(str_num + len - 1) = (num % 10) + 48;
		num = num / 10;
		len--;
	}
	return (str_num);
}
