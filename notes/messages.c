// Funkcja do obsługi wiadomości wyjścia z gry
void	exit_message(t_game *game, char *message, int code)
{
	int		fd; // Zmienna do przechowywania deskryptora pliku
	char	*line; // Zmienna do przechowywania pojedynczej linii z pliku

	// Sprawdzenie, czy podano wiadomość
	if (message)
	{
		ft_printf("%s\n", message); // Wydrukowanie wiadomości
		exit(code); // Zakończenie gry z podanym kodem
	}
	// Wydrukowanie liczby ruchów wykonanych w grze
	ft_printf("You finished the game in %d moves!\n", game->moves);
	fd = open("victory.txt", O_RDONLY); // Otwarcie pliku z wiadomościami zwycięstwa
	line = get_next_line(fd); // Wczytanie pierwszej linii z pliku
	// Pętla do wydruku wszystkich linii z pliku
	while (line)
	{
		ft_printf("%s", line); // Wydrukowanie linii
		free(line); // Zwolnienie pamięci zajmowanej przez linię
		line = get_next_line(fd); // Wczytanie następnej linii
	}
	ft_printf("\n"); // Wydrukowanie nowej linii
	close(fd); // Zamknięcie pliku
	exit(code); // Zakończenie gry z podanym kodem
}

// Funkcja do niszczenia obrazów w grze
void	destroy_images(t_game *game)
{
	// Sprawdzenie i zniszczenie obrazów, jeśli zostały utworzone
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

// Funkcja do zakończenia gry
int	end_game(t_game *game, char *message, int code)
{
	// Sprawdzenie, czy mapa została załadowana
	if (game->map.map)
	{
		// Pętla do zwolnienia pamięci zajmowanej przez mapę
		while (game->map.height--)
			free(game->map.map[game->map.height]); // Zwolnienie pamięci dla każdego wiersza
		free(game->map.map); // Zwolnienie pamięci dla tablicy mapy
	}
	destroy_images(game); // Zniszczenie wszystkich obrazów
	// Sprawdzenie, czy wskaźnik na okno i MLX są ważne przed ich zniszczeniem
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr); // Zniszczenie okna gry
	if (game->mlx_ptr) // Sprawdzenie, czy wskaźnik MLX jest ważny
	{
		mlx_loop_end(game->mlx_ptr); // Zakończenie pętli MLX
		mlx_destroy_display(game->mlx_ptr); // Zniszczenie wyświetlacza MLX
		free(game->mlx_ptr); // Zwolnienie pamięci zajmowanej przez wskaźnik MLX
	}
	exit_message(game, message, code); // Wywołanie funkcji do obsługi wiadomości wyjścia
	return (0); // Zwrócenie wartości 0 (nigdy nie osiągnięte z powodu exit)
}

