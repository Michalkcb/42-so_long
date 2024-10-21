/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michalkcb <michalkcb@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:01:43 by mbany             #+#    #+#             */
/*   Updated: 2024/10/21 20:50:20 by michalkcb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_map(const char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		row;

	if (load_map_size(file, game) == -1)
		return (-1);
	allocate_map_memory(game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening map file");
	row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[row] = ft_strtrim(line, "\n");
		if (!game->map[row])
			ft_error("Error duplicating map line");
		free(line);
		row++;
	}
	game->map[row] = NULL;
	finish_map_validation(fd, game);
	return (0);
}

void	initialize_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Error initializing MLX");
	game->win = mlx_new_window(game->mlx, game->width * 100,
			game->height * 100, "so_long");
	if (!game->win)
		ft_error("Error creating window");
	game->move_count = 0;
	game->collected_items = 0;
	load_textures(game);
	draw_map(game);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0, destroy_window, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long map.ber\n");
		return (1);
	}
	if (load_map(argv[1], &game) == -1)
	{
		ft_printf("Error: Invalid map\n");
		return (1);
	}
	initialize_game(&game);
	mlx_loop(game.mlx);
	return (0);
}