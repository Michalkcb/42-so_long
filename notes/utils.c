// Funkcja otwierająca mapę z pliku o podanej ścieżce.
// Zwraca deskryptor pliku, który jest używany do dalszej interakcji z mapą.
int	open_map(char *path, t_game *game)
{
	int	fd;  // Zmienna przechowująca deskryptor pliku.

	// Próba otwarcia pliku w trybie tylko do odczytu.
	fd = open(path, O_RDONLY);
	// Sprawdzenie, czy otwarcie pliku się nie powiodło.
	if (fd < 0)
		// Zakończenie gry z komunikatem, że mapa nie została znaleziona.
		end_game(game, "Map not found", 1);
	return (fd);  // Zwraca deskryptor pliku, jeśli otwarcie powiodło się.
}

// Funkcja dzieląca linię na nową linię do użycia w mapie.
// Usuwa znak nowej linii i zwraca wskaźnik do nowego łańcucha.
char	*split_line(char *line)
{
	char	*new_line;  // Wskaźnik do nowej linii.
	int		i;  // Zmienna pomocnicza do iteracji.

	// Alokacja pamięci dla nowej linii o długości oryginalnej linii.
	new_line = malloc(ft_strlen(line) * sizeof(char));
	// Sprawdzenie, czy alokacja pamięci powiodła się.
	if (!new_line)
		return (NULL);  // Zwraca NULL w przypadku błędu alokacji.
	i = 0;  // Inicjalizacja zmiennej pomocniczej.
	// Iteracja przez oryginalną linię do momentu napotkania znaku nowej linii.
	while (line[i] != '\n')
	{
		new_line[i] = line[i];  // Kopiowanie znaków do nowej linii.
		i++;
	}
	new_line[i] = '\0';  // Dodanie znaku końca łańcucha.
	free(line);  // Zwolnienie pamięci oryginalnej linii.
	return (new_line);  // Zwrócenie wskaźnika do nowej linii.
}

// Funkcja wyświetlająca liczbę ruchów i kolekcjonowanych przedmiotów na ekranie.
// Aktualizuje widok gry w oknie.
void	display_moves_and_collectibles(t_game *game)
{
	char	*moves;  // Wskaźnik do łańcucha przechowującego liczbę ruchów.
	char	*collectibles;  // Wskaźnik do łańcucha przechowującego liczbę kolekcjonowanych przedmiotów.

	// Konwersja liczby ruchów na łańcuch znaków.
	moves = ft_itoa(game->moves);
	// Konwersja liczby kolekcjonowanych przedmiotów na łańcuch znaków.
	collectibles = ft_itoa(game->collectibles);
	// Wyświetlenie etykiety i liczby ruchów w oknie gry.
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 120, 10, 0x00FFFFFF, moves);
	// Wyświetlenie etykiety i liczby kolekcjonowanych przedmiotów w oknie gry.
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 25, 0x00FFFFFF, "Collectibles: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 120, 25, 0x00FFFFFF, collectibles);
	free(moves);  // Zwolnienie pamięci dla łańcucha ruchów.
	free(collectibles);  // Zwolnienie pamięci dla łańcucha kolekcjonowanych przedmiotów.
}


	// ft_printf("Moves: %s\n", moves);
	// ft_printf("Collectibles: %s\n", collectibles);
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
