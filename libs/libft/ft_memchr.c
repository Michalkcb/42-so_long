/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:48:43 by mbany             #+#    #+#             */
/*   Updated: 2024/10/24 19:48:44 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	char			*find;

	find = (char *)str;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)find[i] == (unsigned char)c)
			return ((void *)&find[i]);
		i++;
	}
	return (0);
}
