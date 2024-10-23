/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:03:54 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:10:20 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlen(const char *str)
{
	int	strlen;

	strlen = 0;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		str += 1;
		strlen += 1;
	}
	return (strlen);
}
