// Funkcja inicjalizująca pozycje gracza i wyjścia na mapie
void	init_positions(t_game *game)
{
	int	x; // Zmienna do iteracji przez szerokość mapy
	int	y; // Zmienna do iteracji przez wysokość mapy

	x = 0; // Inicjalizacja zmiennej x
	// Pętla iterująca przez wszystkie kolumny mapy
	while (x < game->map.width)
	{
		y = 0; // Inicjalizacja zmiennej y dla każdej kolumny
		// Pętla iterująca przez wszystkie wiersze mapy
		while (y < game->map.height)
		{
			// Sprawdzenie, czy w danej pozycji znajduje się gracz ('P')
			if (game->map.map[y][x] == 'P')
			{
				// Zapisanie pozycji gracza
				game->map.x_player_pos = x; 
				game->map.y_player_pos = y;
			}
			// Sprawdzenie, czy w danej pozycji znajduje się wyjście ('E')
			if (game->map.map[y][x] == 'E')
			{
				// Zapisanie pozycji wyjścia
				game->map.x_exit_pos = x;
				game->map.y_exit_pos = y;
			}
			y++; // Przechodzenie do następnego wiersza
		}
		x++; // Przechodzenie do następnej kolumny
	}
}

// Funkcja przesuwająca gracza w górę
void	move_up(t_game *game)
{
	int	x; // Pozycja gracza w osi X
	int	y; // Pozycja gracza w osi Y

	x = game->map.x_player_pos; // Przypisanie aktualnej pozycji gracza w osi X
	y = game->map.y_player_pos; // Przypisanie aktualnej pozycji gracza w osi Y
	// Sprawdzenie, czy pole nad graczem nie jest ścianą ('1')
	if (game->map.map[y - 1][x] != '1')
	{
		game->moves++; // Zwiększenie liczby ruchów
		// Sprawdzenie, czy pole nad graczem zawiera kolekcjonowalny przedmiot ('C')
		if (game->map.map[y - 1][x] == 'C')
			game->collectibles--; // Zmniejszenie liczby kolekcjonowanych przedmiotów
		game->map.map[y][x] = '0'; // Ustawienie aktualnej pozycji gracza na pole puste ('0')
		game->map.map[game->map.y_exit_pos][game->map.x_exit_pos] = 'E'; // Przywrócenie wyjścia na mapie
		// Sprawdzenie, czy gracz znalazł wyjście i czy zebrał wszystkie przedmioty
		if (game->map.map[y - 1][x] == 'E' && game->collectibles == 0)
			end_game(game, NULL, 0); // Zakończenie gry
		game->map.map[y - 1][x] = 'P'; // Ustawienie nowej pozycji gracza na górze
		game->player.direction = 'U'; // Aktualizacja kierunku gracza na 'U' (góra)
		game->map.y_player_pos = y - 1; // Zaktualizowanie pozycji gracza w osi Y
	}
	render_map(game); // Renderowanie mapy po ruchu
}

// Funkcja przesuwająca gracza w dół
void	move_down(t_game *game)
{
	int	x; // Pozycja gracza w osi X
	int	y; // Pozycja gracza w osi Y

	x = game->map.x_player_pos; // Przypisanie aktualnej pozycji gracza w osi X
	y = game->map.y_player_pos; // Przypisanie aktualnej pozycji gracza w osi Y
	// Sprawdzenie, czy pole pod graczem nie jest ścianą ('1')
	if (game->map.map[y + 1][x] != '1')
	{
		game->moves++; // Zwiększenie liczby ruchów
		// Sprawdzenie, czy pole pod graczem zawiera kolekcjonowalny przedmiot ('C')
		if (game->map.map[y + 1][x] == 'C')
			game->collectibles--; // Zmniejszenie liczby kolekcjonowanych przedmiotów
		game->map.map[y][x] = '0'; // Ustawienie aktualnej pozycji gracza na pole puste ('0')
		game->map.map[game->map.y_exit_pos][game->map.x_exit_pos] = 'E'; // Przywrócenie wyjścia na mapie
		// Sprawdzenie, czy gracz znalazł wyjście i czy zebrał wszystkie przedmioty
		if (game->map.map[y + 1][x] == 'E' && game->collectibles == 0)
			end_game(game, NULL, 0); // Zakończenie gry
		game->map.map[y + 1][x] = 'P'; // Ustawienie nowej pozycji gracza na dole
		game->player.direction = 'D'; // Aktualizacja kierunku gracza na 'D' (dół)
		game->map.y_player_pos = y + 1; // Zaktualizowanie pozycji gracza w osi Y
	}
	render_map(game); // Renderowanie mapy po ruchu
}

// Funkcja przesuwająca gracza w lewo
void	move_left(t_game *game)
{
	int	x; // Pozycja gracza w osi X
	int	y; // Pozycja gracza w osi Y

	x = game->map.x_player_pos; // Przypisanie aktualnej pozycji gracza w osi X
	y = game->map.y_player_pos; // Przypisanie aktualnej pozycji gracza w osi Y
	// Sprawdzenie, czy pole po lewej stronie gracza nie jest ścianą ('1')
	if (game->map.map[y][x - 1] != '1')
	{
		game->moves++; // Zwiększenie liczby ruchów
		// Sprawdzenie, czy pole po lewej stronie gracza zawiera kolekcjonowalny przedmiot ('C')
		if (game->map.map[y][x - 1] == 'C')
			game->collectibles--; // Zmniejszenie liczby kolekcjonowanych przedmiotów
		game->map.map[y][x] = '0'; // Ustawienie aktualnej pozycji gracza na pole puste ('0')
		game->map.map[game->map.y_exit_pos][game->map.x_exit_pos] = 'E'; // Przywrócenie wyjścia na mapie
		// Sprawdzenie, czy gracz znalazł wyjście i czy zebrał wszystkie przedmioty
		if (game->map.map[y][x - 1] == 'E' && game->collectibles == 0)
			end_game(game, NULL, 0); // Zakończenie gry
		game->map.map[y][x - 1] = 'P'; // Ustawienie nowej pozycji gracza po lewej
		game->player.direction = 'L'; // Aktualizacja kierunku gracza na 'L' (lewo)
		game->map.x_player_pos = x - 1; // Zaktualizowanie pozycji gracza w osi X
	}
	render_map(game); // Renderowanie mapy po ruchu
}

// Funkcja przesuwająca gracza w prawo
void	move_right(t_game *game)
{
	int	x; // Pozycja gracza w osi X
	int	y; // Pozycja gracza w osi Y

	x = game->map.x_player_pos; // Przypisanie aktualnej pozycji gracza w osi X
	y = game->map.y_player_pos; // Przypisanie aktualnej pozycji gracza w osi Y
	// Sprawdzenie, czy pole po prawej stronie gracza nie jest ścianą ('1')
	if (game->map.map[y][x + 1] != '1')
	{
		game->moves++; // Zwiększenie liczby ruchów
		// Sprawdzenie, czy pole po prawej stronie gracza zawiera kolekcjonowalny przedmiot ('C')
		if (game->map.map[y][x + 1] == 'C')
			game->collectibles--; // Zmniejszenie liczby kolekcjonowanych przedmiotów
		game->map.map[y][x] = '0'; // Ustawienie aktualnej pozycji gracza na pole puste ('0')
		game->map.map[game->map.y_exit_pos][game->map.x_exit_pos] = 'E'; // Przywrócenie wyjścia na mapie
		// Sprawdzenie, czy gracz znalazł wyjście i czy zebrał wszystkie przedmioty
		if (game->map.map[y][x + 1] == 'E' && game->collectibles == 0)
			end_game(game, NULL, 0); // Zakończenie gry
		game->map.map[y][x + 1] = 'P'; // Ustawienie nowej pozycji gracza po prawej
		game->player.direction = 'R'; // Aktualizacja kierunku gracza na 'R' (prawo)
		game->map.x_player_pos = x + 1; // Zaktualizowanie pozycji gracza w osi X
	}
	render_map(game); // Renderowanie mapy po ruchu
}
