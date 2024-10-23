/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:22:25 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/16 14:11:28 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_message(t_game *game, char *message, int code)
{
	int		fd;
	char	*line;

	if (message)
	{
		ft_printf("%s\n", message);
		exit(code);
	}
	ft_printf("You finished the game in %d moves!\n", game->moves);
	fd = open("victory.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("\n");
	close(fd);
	exit(code);
}

void	destroy_images(t_game *game)
{
	if (game->collectible.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collectible.xpm_ptr);
	if (game->exit.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit.xpm_ptr);
	if (game->wall.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	if (game->floor.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	if (game->player.player_r.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_r.xpm_ptr);
	if (game->player.player_l.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_l.xpm_ptr);
	if (game->player.player_u.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_u.xpm_ptr);
	if (game->player.player_d.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_d.xpm_ptr);
}

int	end_game(t_game *game, char *message, int code)
{
	if (game->map.map)
	{
		while (game->map.height--)
			free(game->map.map[game->map.height]);
		free(game->map.map);
	}
	destroy_images(game);
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_loop_end(game->mlx_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit_message(game, message, code);
	return (0);
}
