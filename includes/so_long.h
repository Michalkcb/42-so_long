/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:30:50 by mbany             #+#    #+#             */
/*   Updated: 2024/10/22 20:05:18 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#include <stdio.h>

# define TILE_SIZE 32
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600


typedef struct s_textures
{
    void *bg;
    void *wall;
    void *player;
    void *collectible;
    void *exit;
    void *exit_open;
} t_textures;

typedef struct s_game
{
    void *mlx;
    void *win;
    t_textures textures;
    char **map;
} t_game;

int handle_keypress(int keycode, t_game *game);
int load_textures(t_game *game);
int load_textures(t_game *game);
int load_map(t_game *game, char *file);
void draw_map(t_game *game);
int ft_error(char *message);






    #define KEY_W 119  // Kod klawisza 'W' na Linuxie
    #define KEY_A 97   // Kod klawisza 'A' na Linuxie
    #define KEY_S 115  // Kod klawisza 'S' na Linuxie
    #define KEY_D 100  // Kod klawisza 'D' na Linuxie
    #define KEY_ESC 65307  // Kod ESC na Linuxie

#endif
