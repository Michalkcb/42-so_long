/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michalkcb <michalkcb@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:11:58 by mbany             #+#    #+#             */
/*   Updated: 2024/10/26 22:55:04 by michalkcb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game, char *path)
{
	int		fd;
	int		rec_check;
	char	*line;

	rec_check = 0;
	fd = open_map(path, game);
	line = get_next_line(fd);
	if (!line)
		end_game(game, "No map", 1);
	if (ft_strchr(line, '\n') != 0)
		line = split_line(line);
	game->map.width = ft_strlen(line);
	while (line)
	{
		if ((int)ft_strlen(line) != game->map.width)
			rec_check = 1;
		game->map.height++;
		free(line);
		line = get_next_line(fd);
		if (ft_strchr(line, '\n') != 0)
			line = split_line(line);
	}
	close(fd);
	if (rec_check == 1)
		end_game(game, "Map not rectangular", 1);
}

void	fill_map(t_game *game, char *path)
{
	int		fd;
	char	*line;
	int		i;

	if (game->map.height <= 3 || game->map.width <= 3)
		end_game(game, "Map too small", 1);
	fd = open_map(path, game);
	game->map.map = malloc(game->map.height * sizeof(char *));
	if (!game->map.map)
		end_game(game, "Malloc error", 1);
	i = 0;
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		game->map.map[i] = malloc((game->map.width + 1) * sizeof(char));
		if (!game->map.map[i])
			end_game(game, "Malloc error", 1);
		ft_strlcpy(game->map.map[i], line, game->map.width + 1);
		free(line);
		i++;
	}
	close(fd);
}

void	validate_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (ft_strchr("01CEPT", game->map.map[i][j]) == NULL)
				end_game(game, "Invalid element on the map", 1);
			j++;
		}
		i++;
	}
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (i == 0 || i == game->map.height)
			{
				if (game->map.map[i][j] != '1')
					end_game(game, "Invalid wall", 1);
			}
			if (j == 0 || j == game->map.width - 1)
			{
				if (game->map.map[i][j] != '1')
					end_game(game, "Invalid wall", 1);
			}
			j++;
		}
		i++;
	}
}

void	count_elements(t_game *game)
{
	int	i;
	int	j;
	int	player;
	int	exit;

	i = 0;
	player = 0;
	exit = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'C')
				game->collectibles++;
			if (game->map.map[i][j] == 'P')
				player++;
			if (game->map.map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (game->collectibles == 0 || player != 1 || exit != 1)
		end_game(game, "Wrong number of elements on the map", 1);
}
