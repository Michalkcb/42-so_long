/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:25:26 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:11:31 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_printchar((int)*str);
		i++;
		str++;
	}
	return (i);
}
