/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:31:31 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/16 15:12:19 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_positions(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.width)
	{
		y = 0;
		while (y < game->map.height)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->map.x_player_pos = x;
				game->map.y_player_pos = y;
			}
			if (game->map.map[y][x] == 'E')
			{
				game->map.x_exit_pos = x;
				game->map.y_exit_pos = y;
			}
			y++;
		}
		x++;
	}
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x_player_pos;
	y = game->map.y_player_pos;
	if (game->map.map[y - 1][x] != '1')
	{
		game->moves++;
		if (game->map.map[y - 1][x] == 'C')
			game->collectibles--;
		game->map.map[y][x] = '0';
		game->map.map[game->map.y_exit_pos][game->map.x_exit_pos] = 'E';
		if (game->map.map[y - 1][x] == 'E' && game->collectibles == 0)
			end_game(game, NULL, 0);
		game->map.map[y - 1][x] = 'P';
		game->player.direction = 'U';
		game->map.y_player_pos = y - 1;
	}
	render_map(game);
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x_player_pos;
	y = game->map.y_player_pos;
	if (game->map.map[y + 1][x] != '1')
	{
		game->moves++;
		if (game->map.map[y + 1][x] == 'C')
			game->collectibles--;
		game->map.map[y][x] = '0';
		game->map.map[game->map.y_exit_pos][game->map.x_exit_pos] = 'E';
		if (game->map.map[y + 1][x] == 'E' && game->collectibles == 0)
			end_game(game, NULL, 0);
		game->map.map[y + 1][x] = 'P';
		game->player.direction = 'D';
		game->map.y_player_pos = y + 1;
	}
	render_map(game);
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x_player_pos;
	y = game->map.y_player_pos;
	if (game->map.map[y][x - 1] != '1')
	{
		game->moves++;
		if (game->map.map[y][x - 1] == 'C')
			game->collectibles--;
		game->map.map[y][x] = '0';
		game->map.map[game->map.y_exit_pos][game->map.x_exit_pos] = 'E';
		if (game->map.map[y][x - 1] == 'E' && game->collectibles == 0)
			end_game(game, NULL, 0);
		game->map.map[y][x - 1] = 'P';
		game->player.direction = 'L';
		game->map.x_player_pos = x - 1;
	}
	render_map(game);
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x_player_pos;
	y = game->map.y_player_pos;
	if (game->map.map[y][x + 1] != '1')
	{
		game->moves++;
		if (game->map.map[y][x + 1] == 'C')
			game->collectibles--;
		game->map.map[y][x] = '0';
		game->map.map[game->map.y_exit_pos][game->map.x_exit_pos] = 'E';
		if (game->map.map[y][x + 1] == 'E' && game->collectibles == 0)
			end_game(game, NULL, 0);
		game->map.map[y][x + 1] = 'P';
		game->player.direction = 'R';
		game->map.x_player_pos = x + 1;
	}
	render_map(game);
}
