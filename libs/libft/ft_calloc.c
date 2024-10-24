/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:50:10 by mbany             #+#    #+#             */
/*   Updated: 2024/10/24 19:50:10 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t items, size_t size)
{
	void	*buffer;

	if (items > sizeof(size_t) && size > sizeof(size_t))
		return (0);
	buffer = malloc(items * size);
	if (!buffer)
		return (0);
	else
		ft_bzero(buffer, items * size);
	return (buffer);
}
