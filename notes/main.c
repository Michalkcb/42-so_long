static int	key_hook(int keycode, t_game *game)
{
	// Sprawdza, czy klawisz ESC lub Q został naciśnięty; jeśli tak, kończy grę.
	if (keycode == KEY_ESC || keycode == KEY_Q)
		end_game(game, "Goodbye!", 0);
	// Jeśli wciśnięty klawisz to W lub strzałka w górę, wywołuje funkcję ruchu w górę.
	else if (keycode == KEY_W || keycode == KEY_AR_U)
	{
		move_up(game);
	}
	// Jeśli wciśnięty klawisz to S lub strzałka w dół, wywołuje funkcję ruchu w dół.
	else if (keycode == KEY_S || keycode == KEY_AR_D)
	{
		move_down(game);
	}
	// Jeśli wciśnięty klawisz to A lub strzałka w lewo, wywołuje funkcję ruchu w lewo.
	else if (keycode == KEY_A || keycode == KEY_AR_L)
	{
		move_left(game);
	}
	// Jeśli wciśnięty klawisz to D lub strzałka w prawo, wywołuje funkcję ruchu w prawo.
	else if (keycode == KEY_D || keycode == KEY_AR_R)
	{
		move_right(game);
	}
	return (0);
}

static void	init_game(t_game *game)
{
	// Ustawia wskaźniki i zmienne gry na wartości początkowe.
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->collectibles = 0; // Licznik przedmiotów do zebrania ustawiony na 0.
	game->moves = 0; // Licznik ruchów gracza ustawiony na 0.
	game->map.map = NULL; // Wskaźnik do mapy ustawiony na NULL.
	game->map.width = 0;
	game->map.height = 0;
	game->map.x_player_pos = 0; // Początkowe współrzędne gracza na mapie.
	game->map.y_player_pos = 0;
	game->map.x_exit_pos = 0; // Początkowe współrzędne wyjścia na mapie.
	game->map.y_exit_pos = 0;
	// Wskaźniki do zasobów graficznych ustawione na NULL.
	game->collectible.xpm_ptr = NULL;
	game->exit.xpm_ptr = NULL;
	game->wall.xpm_ptr = NULL;
	game->floor.xpm_ptr = NULL;
	game->player.direction = 'R'; // Początkowy kierunek gracza - w prawo.
	game->player.player_r.xpm_ptr = NULL;
	game->player.player_l.xpm_ptr = NULL;
	game->player.player_u.xpm_ptr = NULL;
	game->player.player_d.xpm_ptr = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	// Sprawdza, czy przekazano argument z nazwą pliku mapy.
	if (argc <= 1)
		return (1);

	init_game(&game); // Inicjalizuje strukturę gry.
	game.mlx_ptr = mlx_init(); // Inicjalizuje połączenie z X serverem dla grafiki.
	if (!game.mlx_ptr)
		return (1);

	init_sprites(&game); // Ładuje zasoby graficzne do gry.
	read_map(&game, argv[1]); // Wczytuje plik mapy.
	fill_map(&game, argv[1]); // Wypełnia strukturę mapy na podstawie danych z pliku.
	validate_elements(&game); // Waliduje, czy mapa zawiera odpowiednie elementy.
	check_walls(&game); // Sprawdza, czy mapa jest otoczona ścianami.
	count_elements(&game); // Liczy wymagane elementy mapy (gracz, wyjście, przedmioty).

	// Tworzy okno gry o rozmiarach dopasowanych do mapy.
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map.width * SPRITE_SIZE,
			game.map.height * SPRITE_SIZE, "Let's play So Long!");
	if (!game.win_ptr)
		return (1);

	init_positions(&game); // Ustawia początkowe pozycje gracza i wyjścia na mapie.
	mlx_key_hook(game.win_ptr, key_hook, &game); // Rejestruje obsługę klawiszy.
	mlx_hook(game.win_ptr, CLOSE_BTN, 0, end_game, &game); // Obsługa zamknięcia okna.
	mlx_hook(game.win_ptr, EXPOSE, EXPOSURE_MASK, render_map, &game); // Renderowanie mapy.

	mlx_loop(game.mlx_ptr); // Rozpoczyna pętlę zdarzeń, która obsługuje grę.
	return (0);
}
