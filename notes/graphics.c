
// Funkcja inicjalizująca sprity (obiekty graficzne) w grze
void	init_sprites(t_game *game)
{
	// Tworzenie sprita dla przedmiotu kolekcjonerskiego
	game->collectible = create_sprite(game, COLLECTIBLE);
	// Tworzenie sprita dla wyjścia
	game->exit = create_sprite(game, EXIT);
	// Tworzenie sprita dla ściany
	game->wall = create_sprite(game, WALL);
	// Tworzenie sprita dla podłogi
	game->floor = create_sprite(game, FLOOR);
	// Tworzenie sprita dla gracza w kierunku w prawo
	game->player.player_r = create_sprite(game, PLAYER_R);
	// Tworzenie sprita dla gracza w kierunku w lewo
	game->player.player_l = create_sprite(game, PLAYER_L);
	// Tworzenie sprita dla gracza w kierunku w górę
	game->player.player_u = create_sprite(game, PLAYER_U);
	// Tworzenie sprita dla gracza w kierunku w dół
	game->player.player_d = create_sprite(game, PLAYER_D);
}

// Funkcja do tworzenia sprita na podstawie podanej ścieżki do pliku
t_image	create_sprite(t_game *game, char *path)
{
	t_image	sprite; // Zmienna do przechowywania informacji o spricie

	// Ładowanie obrazu sprita z pliku XPM
	sprite.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&sprite.x, &sprite.y);
	// Sprawdzenie, czy udało się załadować sprita
	if (!sprite.xpm_ptr)
		end_game(game, "Failed to load sprite", 1); // Zakończenie gry w przypadku błędu
	return (sprite); // Zwrócenie załadowanego sprita
}

// Funkcja do renderowania sprita na oknie gry w określonym wierszu i kolumnie
void	render_sprite(t_game *game, t_image *sprite, int line, int column)
{
	// Umieszczanie obrazu sprita w oknie gry na określonej pozycji
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->xpm_ptr,
		column * SPRITE_SIZE, line * SPRITE_SIZE);
}

// Funkcja renderująca sprita gracza w zależności od kierunku
void	render_player(t_game *game, int line, int column)
{
	// Sprawdzenie kierunku, w którym zwrócony jest gracz
	if (game->player.direction == 'R') // Gracz zwrócony w prawo
		render_sprite(game, &game->player.player_r, line, column);
	else if (game->player.direction == 'L') // Gracz zwrócony w lewo
		render_sprite(game, &game->player.player_l, line, column);
	else if (game->player.direction == 'U') // Gracz zwrócony w górę
		render_sprite(game, &game->player.player_u, line, column);
	else if (game->player.direction == 'D') // Gracz zwrócony w dół
		render_sprite(game, &game->player.player_d, line, column);
}

// Funkcja do renderowania całej mapy
int	render_map(t_game *game)
{
	int	line; // Zmienna do iteracji po wierszach
	int	column; // Zmienna do iteracji po kolumnach

	line = 0; // Inicjalizacja zmiennej line
	// Pętla iterująca po wierszach mapy
	while (line < game->map.height)
	{
		column = 0; // Inicjalizacja zmiennej column dla każdego wiersza
		// Pętla iterująca po kolumnach mapy
		while (column < game->map.width)
		{
			// Renderowanie sprita wyjścia, jeśli na danej pozycji jest 'E'
			if (game->map.map[line][column] == 'E')
				render_sprite(game, &game->exit, line, column);
			// Renderowanie sprita kolekcjonerskiego, jeśli na danej pozycji jest 'C'
			if (game->map.map[line][column] == 'C')
				render_sprite(game, &game->collectible, line, column);
			// Renderowanie sprita ściany, jeśli na danej pozycji jest '1'
			if (game->map.map[line][column] == '1')
				render_sprite(game, &game->wall, line, column);
			// Renderowanie sprita podłogi, jeśli na danej pozycji jest '0'
			if (game->map.map[line][column] == '0')
				render_sprite(game, &game->floor, line, column);
			// Renderowanie sprita gracza, jeśli na danej pozycji jest 'P'
			if (game->map.map[line][column] == 'P')
				render_player(game, line, column);
			column++; // Przechodzenie do następnej kolumny
		}
		line++; // Przechodzenie do następnego wiersza
	}
	display_moves_and_collectibles(game); // Wyświetlenie liczby ruchów i przedmiotów kolekcjonerskich
	return (0); // Zwrócenie 0 po zakończeniu renderowania mapy
}
