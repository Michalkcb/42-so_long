/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:40:55 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:10:29 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n);

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	char	*s;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	s = (char *)src;
	if (n == 0 && !dst)
		return (len_src);
	if (n <= len_dst)
		return (n + len_src);
	while (i < (n - len_dst - 1) && s[i] != '\0' )
	{
		dst[len_dst + i] = s[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
