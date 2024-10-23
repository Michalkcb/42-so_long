/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:11:16 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:11:01 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*dupl;

	s_len = ft_strlen(s);
	dupl = ft_calloc(s_len + 1, sizeof(char));
	ft_memcpy(dupl, s, s_len + 1);
	return (dupl);
}
