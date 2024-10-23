/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:57:50 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:11:58 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dest);
}
