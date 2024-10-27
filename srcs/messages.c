/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michalkcb <michalkcb@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:11:24 by mbany             #+#    #+#             */
/*   Updated: 2024/10/27 21:21:12 by michalkcb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_message_from_file(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	exit_message(t_game *game, char *message, int code)
{
	if (message && ft_strcmp(message, "Loose") == 0)
		print_message_from_file("loss.txt");
	else if (message && ft_strcmp(message, "Win") == 0)
	{
		ft_printf("You finished the game in %d moves!\n", game->moves);
		print_message_from_file("victory.txt");
	}
	else if (message)
		print_message_from_file("abort.txt");
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
