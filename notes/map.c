// Funkcja do odczytu mapy z pliku i sprawdzania jej poprawności
void	read_map(t_game *game, char *path)
{
	int		fd; // Deskryptor pliku
	int		rec_check; // Flaga do sprawdzenia, czy mapy są prostokątne
	char	*line; // Linia odczytana z pliku

	rec_check = 0; // Inicjalizacja flagi
	fd = open_map(path, game); // Otwórz mapę i uzyskaj deskryptor pliku
	line = get_next_line(fd); // Odczytaj pierwszą linię z pliku
	// Sprawdzenie, czy linia jest pusta (błąd mapy)
	if (!line)
		end_game(game, "No map", 1);
	// Sprawdzenie, czy linia zawiera nową linię, a jeśli tak, rozdzielenie jej
	if (ft_strchr(line, '\n') != 0)
		line = split_line(line);
	game->map.width = ft_strlen(line); // Ustal szerokość mapy na podstawie długości linii
	// Pętla odczytująca wszystkie linie mapy
	while (line)
	{
		// Sprawdzenie, czy długość linii jest różna od szerokości mapy (sprawdzanie prostokątności)
		if ((int)ft_strlen(line) != game->map.width)
			rec_check = 1; // Ustawienie flagi, jeśli mapy są nieprostokątne
		game->map.height++; // Zwiększenie wysokości mapy
		free(line); // Zwolnienie pamięci zajmowanej przez odczytaną linię
		line = get_next_line(fd); // Odczytanie następnej linii
		// Powtórne rozdzielenie, jeśli linia zawiera nową linię
		if (ft_strchr(line, '\n') != 0)
			line = split_line(line);
	}
	close(fd); // Zamknięcie deskryptora pliku
	// Sprawdzenie, czy flaga prostokątności została ustawiona
	if (rec_check == 1)
		end_game(game, "Map not rectangular", 1); // Zakończenie gry, jeśli mapy są nieprostokątne
}

// Funkcja do wypełnienia mapy danymi z pliku
void	fill_map(t_game *game, char *path)
{
	int		fd; // Deskryptor pliku
	char	*line; // Linia odczytana z pliku
	int		i; // Indeks do iteracji po wysokości mapy

	// Sprawdzenie, czy mapa jest wystarczająco duża
	if (game->map.height <= 3 || game->map.width <= 3)
		end_game(game, "Map too small", 1); // Zakończenie gry, jeśli mapa jest za mała
	fd = open_map(path, game); // Otwórz mapę
	// Alokacja pamięci dla mapy
	game->map.map = malloc(game->map.height * sizeof(char *));
	if (!game->map.map) // Sprawdzenie, czy alokacja się powiodła
		end_game(game, "Malloc error", 1);
	i = 0; // Inicjalizacja indeksu
	// Pętla odczytująca każdą linię mapy
	while (i < game->map.height)
	{
		line = get_next_line(fd); // Odczytanie linii
		// Alokacja pamięci dla danej linii mapy
		game->map.map[i] = malloc((game->map.width + 1) * sizeof(char));
		if (!game->map.map[i]) // Sprawdzenie, czy alokacja się powiodła
			end_game(game, "Malloc error", 1);
		ft_strlcpy(game->map.map[i], line, game->map.width + 1); // Skopiowanie linii do mapy
		free(line); // Zwolnienie pamięci zajmowanej przez odczytaną linię
		i++; // Zwiększenie indeksu
	}
	close(fd); // Zamknięcie deskryptora pliku
}

// Funkcja do walidacji elementów na mapie
void	validate_elements(t_game *game)
{
	int	i; // Indeks do iteracji po wysokości mapy
	int	j; // Indeks do iteracji po szerokości mapy

	i = 0; // Inicjalizacja indeksu w osi Y
	// Pętla sprawdzająca każdy element na mapie
	while (i < game->map.height)
	{
		j = 0; // Inicjalizacja indeksu w osi X
		while (j < game->map.width)
		{
			// Sprawdzenie, czy element jest jednym z dozwolonych ('0', '1', 'C', 'E', 'P')
			if (ft_strchr("01CEP", game->map.map[i][j]) == NULL)
				end_game(game, "Invalid element on the map", 1); // Zakończenie gry, jeśli element jest nieprawidłowy
			j++; // Zwiększenie indeksu w osi X
		}
		i++; // Zwiększenie indeksu w osi Y
	}
}

// Funkcja do sprawdzania ścian mapy
void	check_walls(t_game *game)
{
	int	i; // Indeks do iteracji po wysokości mapy
	int	j; // Indeks do iteracji po szerokości mapy

	i = 0; // Inicjalizacja indeksu w osi Y
	// Pętla sprawdzająca każdy element na mapie
	while (i < game->map.height)
	{
		j = 0; // Inicjalizacja indeksu w osi X
		while (j < game->map.width)
		{
			// Sprawdzenie, czy jesteśmy na górnej lub dolnej krawędzi mapy
			if (i == 0 || i == game->map.height)
			{
				if (game->map.map[i][j] != '1') // Sprawdzenie, czy pole jest ścianą
					end_game(game, "Invalid wall", 1); // Zakończenie gry, jeśli nie jest
			}
			// Sprawdzenie, czy jesteśmy na lewej lub prawej krawędzi mapy
			if (j == 0 || j == game->map.width - 1)
			{
				if (game->map.map[i][j] != '1') // Sprawdzenie, czy pole jest ścianą
					end_game(game, "Invalid wall", 1); // Zakończenie gry, jeśli nie jest
			}
			j++; // Zwiększenie indeksu w osi X
		}
		i++; // Zwiększenie indeksu w osi Y
	}
}

// Funkcja do liczenia elementów na mapie (kolekcjonowalne, gracz, wyjście)
void	count_elements(t_game *game)
{
	int	i; // Indeks do iteracji po wysokości mapy
	int	j; // Indeks do iteracji po szerokości mapy
	int	player; // Licznik graczy
	int	exit; // Licznik wyjść

	i = 0; // Inicjalizacja indeksu w osi Y
	player = 0; // Inicjalizacja licznika graczy
	exit = 0; // Inicjalizacja licznika wyjść
	// Pętla sprawdzająca każdy element na mapie
	while (i < game->map.height)
	{
		j = 0; // Inicjalizacja indeksu w osi X
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'C') // Sprawdzenie, czy element to kolekcjonowalny przedmiot
				game->collectibles++; // Zwiększenie licznika kolekcjonowanych przedmiotów
			if (game->map.map[i][j] == 'P') // Sprawdzenie, czy element to gracz
				player++; // Zwiększenie licznika graczy
			if (game->map.map[i][j] == 'E') // Sprawdzenie, czy element to wyjście
				exit++; // Zwiększenie licznika wyjść
			j++; // Zwiększenie indeksu w osi X
		}
		i++; // Zwiększenie indeksu w osi Y
	}
	// Sprawdzenie, czy liczba kolekcjonowanych przedmiotów, graczy i wyjść jest poprawna
	if (game->collectibles == 0 || player != 1 || exit != 1)
		end_game(game, "Wrong number of elements on the map", 1); // Zakończenie gry, jeśli liczby są niepoprawne
}


// Funkcja do liczenia elementów na mapie (kolekcjonowalne, gracz, wyjście)
void	count_elements(t_game *game)
{
	int	i; // Indeks do iteracji po wysokości mapy
	int	j; // Indeks do iteracji po szerokości mapy
	int	player; // Licznik graczy
	int	exit; // Licznik wyjść

	i = 0; // Inicjalizacja indeksu w osi Y
	player = 0; // Inicjalizacja licznika graczy
	exit = 0; // Inicjalizacja licznika wyjść
	// Pętla sprawdzająca każdy element na mapie
	while (i < game->map.height)
	{
		j = 0; // Inicjalizacja indeksu w osi X
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'C') // Sprawdzenie, czy element to kolekcjonowalny przedmiot
				game->collectibles++; // Zwiększenie licznika kolekcjonowanych przedmiotów
			if (game->map.map[i][j] == 'P') // Sprawdzenie, czy element to gracz
				player++; // Zwiększenie licznika graczy
			if (game->map.map[i][j] == 'E') // Sprawdzenie, czy element to wyjście
				exit++; // Zwiększenie licznika wyjść
			j++; // Zwiększenie indeksu w osi X
		}
		i++; // Zwiększenie indeksu w osi Y
	}
	// Sprawdzenie, czy liczba kolekcjonowanych przedmiotów, graczy i wyjść jest poprawna
	if (game->collectibles == 0 || player != 1 || exit != 1)
		end_game(game, "Wrong number of elements on the map", 1); // Zakończenie gry, jeśli liczby są niepoprawne
}

