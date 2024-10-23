/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:28:59 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:12:32 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_calloc(size_t nmemb, size_t size)
{
	long	ovflow;
	void	*array;

	ovflow = nmemb * size;
	if (ovflow >= 2147483647)
		return (0);
	if (((int)nmemb < 0 && (int)size < 0) || (int)nmemb * (int)size < 0)
		return (0);
	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (0);
	ft_bzero(array, (nmemb * size));
	return (array);
}
