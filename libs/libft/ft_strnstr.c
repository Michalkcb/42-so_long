/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:46:40 by mbany             #+#    #+#             */
/*   Updated: 2024/10/24 19:46:40 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t n)
{
	size_t	i;
	size_t	j;
	char	*big;

	big = (char *)b;
	i = 0;
	if (l[0] == '\0')
		return (big);
	if (n == 0)
		return (0);
	while (big[i] != '\0' && i < n)
	{
		j = 0;
		while (big[i + j] == l[j] && i + j < n)
		{
			if (l[j + 1] == '\0')
				return (big + i);
			j++;
		}
		i++;
	}
	return (0);
}
