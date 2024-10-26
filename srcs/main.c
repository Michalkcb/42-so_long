/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:12:11 by mbany             #+#    #+#             */
/*   Updated: 2024/10/26 14:47:52 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
		// draw_map(game);
		// draw_map(game);
		// draw_map(game);
		// draw_map(game);

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		end_game(game, "Goodbye!", 0);
	else if (keycode == KEY_W || keycode == KEY_AR_U)
	{
		move_up(game);
	}
	else if (keycode == KEY_S || keycode == KEY_AR_D)
	{
		move_down(game);
	}
	else if (keycode == KEY_A || keycode == KEY_AR_L)
	{
		move_left(game);
	}
	else if (keycode == KEY_D || keycode == KEY_AR_R)
	{
		move_right(game);
	}
	return (0);
}

static void	init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->collectibles = 0;
	game->moves = 0;
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.x_player_pos = 0;
	game->map.y_player_pos = 0;
	game->map.x_exit_pos = 0;
	game->map.y_exit_pos = 0;
	game->collectible.xpm_ptr = NULL;
	game->exit.xpm_ptr = NULL;
	game->wall.xpm_ptr = NULL;
	game->floor.xpm_ptr = NULL;
	game->player.direction = 'R';
	game->player.player_r.xpm_ptr = NULL;
	game->player.player_l.xpm_ptr = NULL;
	game->player.player_u.xpm_ptr = NULL;
	game->player.player_d.xpm_ptr = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc <= 1)
		return (1);
	init_game(&game);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);
	init_sprites(&game);
	read_map(&game, argv[1]);
	fill_map(&game, argv[1]);
	validate_elements(&game);
	check_walls(&game);
	count_elements(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map.width * SPRITE_SIZE,
			game.map.height * SPRITE_SIZE, "Let's play So Long!");
	if (!game.win_ptr)
		return (1);
	init_positions(&game);
	mlx_key_hook(game.win_ptr, key_hook, &game);
	mlx_hook(game.win_ptr, CLOSE_BTN, 0, end_game, &game);
	mlx_hook(game.win_ptr, EXPOSE, EXPOSURE_MASK, render_map, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
