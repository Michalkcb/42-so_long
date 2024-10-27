/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:12:40 by mbany             #+#    #+#             */
/*   Updated: 2024/10/27 15:56:50 by mbany            ###   ########.fr       */
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
			end_game(game, "Win", 1);
		if (game->map.map[y - 1][x] == 'T')
			end_game(game, "Loose", 1);
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
			end_game(game, "Win", 1);
		if (game->map.map[y + 1][x] == 'T')
			end_game(game, "Loose", 1);
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
			end_game(game, "Win", 1);
		if (game->map.map[y][x - 1] == 'T')
			end_game(game, "Loose", 1);
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
			end_game(game, "Win", 1);
		if (game->map.map[y][x + 1] == 'T')
			end_game(game, "Loose", 1);
		game->map.map[y][x + 1] = 'P';
		game->player.direction = 'R';
		game->map.x_player_pos = x + 1;
	}
	render_map(game);
}
