/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:03:58 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:09:42 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	end;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	end = 0;
	if (start < s_len)
		end = s_len - start;
	else
		return ((char *)ft_calloc((1), sizeof(char)));
	if (end > len)
		end = len;
	ret = (char *)ft_calloc((end + 1), sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, end + 1);
	return (ret);
}
