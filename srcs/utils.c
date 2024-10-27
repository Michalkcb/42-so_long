/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:11:34 by mbany             #+#    #+#             */
/*   Updated: 2024/10/27 16:37:10 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *path, t_game *game)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		end_game(game, "Map not found", 1);
	return (fd);
}

char	*split_line(char *line)
{
	char	*new_line;
	int		i;

	new_line = malloc(ft_strlen(line) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

void	display_moves_and_collectibles(t_game *game)
{
	char	*moves;
	char	*collectibles;

	moves = ft_itoa(game->moves);
	collectibles = ft_itoa(game->collectibles);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 120, 10, 0x00FFFFFF, moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 25,
		0x00FFFFFF, "Collectibles: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 120, 25,
		0x00FFFFFF, collectibles);
	free(moves);
	free(collectibles);
}

void	ft_insert_pic(int line, int column, t_game *game)
{
	if (game->map.map[line][column] == 'E')
		render_sprite(game, &game->exit, line, column);
	if (game->map.map[line][column] == 'C')
		render_sprite(game, &game->collectible, line, column);
	if (game->map.map[line][column] == '1')
		render_sprite(game, &game->wall, line, column);
	if (game->map.map[line][column] == '0')
		render_sprite(game, &game->floor, line, column);
	if (game->map.map[line][column] == 'P')
		render_player(game, line, column);
	if (game->map.map[line][column] == 'T')
		render_sprite(game, &game->enemy, line, column);
}
