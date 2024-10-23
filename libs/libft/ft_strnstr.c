/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:08:31 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:10:05 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;

	if (!big && !len)
		return (0);
	if (*little == '\0' || big == little)
		return ((char *)big);
	while (*big != '\0' && len--)
	{
		j = 0;
		while (*(big + j) == *(little + j) && *(little + j) && j <= len)
		{
			if (*(little + j + 1) == '\0')
				return ((char *)big);
			j++;
		}
		big++;
	}
	return (0);
}
