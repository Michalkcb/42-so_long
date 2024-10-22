/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:27:50 by mbany             #+#    #+#             */
/*   Updated: 2024/10/22 19:22:36 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int load_map(t_game *game, char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);

    // Przeczytaj zawartość pliku i załaduj do struktury mapy
    // Kod obsługujący mapę, np. zapisanie jej jako tablicy 2D

    close(fd);
    return (1);
}

void draw_map(t_game *game)
{
    int x, y;

    for (y = 0; game->map[y]; y++)
    {
        for (x = 0; game->map[y][x]; x++)
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.player, x * TILE_SIZE, y * TILE_SIZE);
            // Inne elementy mapy
        }
    }
}
