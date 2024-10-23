/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:05:59 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/24 09:57:32 by dmodrzej         ###   ########.fr       */
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
	// ft_printf("Moves: %s\n", moves);
	// ft_printf("Collectibles: %s\n", collectibles);
	free(moves);
	free(collectibles);
}

// void	draw_map(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->map.height)
// 	{
// 		ft_printf("%s\n", game->map.map[i]);
// 		i++;
// 	}
// 	ft_printf("x_player_pos: %d\n", game->map.x_player_pos);
// 	ft_printf("y_player_pos: %d\n", game->map.y_player_pos);
// 	ft_printf("x_exit_pos: %d\n", game->map.x_exit_pos);
// 	ft_printf("y_exit_pos: %d\n", game->map.y_exit_pos);
// 	ft_printf("moves: %d\n", game->moves);
// 	ft_printf("collectibles: %d\n", game->collectibles);
// 	ft_printf("\n");
// }
