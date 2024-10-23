/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:33:59 by mbany             #+#    #+#             */
/*   Updated: 2024/10/12 13:11:10 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c);

static int	wrd_cnt(char *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (i);
}

static char	*ft_wrddup(const char *str, int start, int end)
{
	char	*wrd;
	int		i;

	i = 0;
	wrd = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		*(wrd + i++) = *(str + start++);
	*(wrd + i) = '\0';
	return (wrd);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	int			ind;
	char		**strs;

	strs = (char **)malloc((wrd_cnt((char *)s, c) + 1) * sizeof(char *));
	if (!s || !(strs))
		return (0);
	i = 0;
	j = 0;
	ind = -1;
	while (i <= ft_strlen(s))
	{
		if (*(s + i) != c && ind < 0)
			ind = i;
		else if ((*(s + i) == c || i == ft_strlen(s)) && ind >= 0)
		{
			*(strs + j++) = ft_wrddup(s, ind, i);
			ind = -1;
		}
		i++;
	}
	strs[j] = 0;
	return (strs);
}
