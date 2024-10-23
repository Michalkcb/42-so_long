/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:27:38 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:11:05 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while ((char)c != *p)
	{
		if (!*p)
			return (0);
		p++;
	}
	return (p);
}
