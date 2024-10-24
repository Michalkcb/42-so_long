/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:48:39 by mbany             #+#    #+#             */
/*   Updated: 2024/10/24 19:48:39 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!str1 && !str2)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)str1)[i] > ((unsigned char *)str2)[i])
			return (1);
		else if (((unsigned char *)str1)[i] < ((unsigned char *)str2)[i])
			return (-1);
		else
			i++;
	}
	return (0);
}
