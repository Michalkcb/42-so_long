/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:30:03 by mbany             #+#    #+#             */
/*   Updated: 2024/10/22 19:22:47 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game);
    if (keycode == KEY_W)
        move_player(game, 0, -1); // Ruch w górę
    if (keycode == KEY_S)
        move_player(game, 0, 1);  // Ruch w dół
    if (keycode == KEY_A)
        move_player(game, -1, 0); // Ruch w lewo
    if (keycode == KEY_D)
        move_player(game, 1, 0);  // Ruch w prawo
    return (0);
}
