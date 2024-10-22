/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:35:03 by mbany             #+#    #+#             */
/*   Updated: 2024/10/22 19:44:47 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void draw_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.bg, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.player, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'e')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.exit_open, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}
