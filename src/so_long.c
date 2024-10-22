/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:01:43 by mbany             #+#    #+#             */
/*   Updated: 2024/10/22 19:22:18 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    // Inicjalizacja MiniLibX
    game.mlx = mlx_init();
    if (!game.mlx)
        return (ft_error("Error initializing mlx"));

    // Tworzenie okna
    game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");

    // Ładowanie mapy i tekstur
    if (argc != 2 || !load_map(&game, argv[1]) || !load_textures(&game))
        return (ft_error("Error loading map or textures"));

    // Rysowanie początkowej mapy
    draw_map(&game);

    // Rejestrowanie zdarzeń
    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_loop(game.mlx);  // Pętla MiniLibX

    return (0);
}
