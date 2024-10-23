/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:27:38 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:09:58 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		slen;

	slen = ft_strlen(s);
	p = (char *)s + slen;
	while (p >= s)
	{
		if (*p == (char)c)
			return (p);
		p--;
	}
	return (0);
}
