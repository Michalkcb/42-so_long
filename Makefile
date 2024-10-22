# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 18:56:26 by mbany             #+#    #+#              #
#    Updated: 2024/10/22 19:44:54 by mbany            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nazwa pliku wykonywalnego
NAME = so_long

# Pliki źródłowe
SRCS = src/so_long.c src/draw_map.c src/load_map.c src/events.c

# Pliki obiektowe
OBJS = $(SRCS:.c=.o)

# Kompilator
CC = gcc

# Flagi kompilatora
CFLAGS = -Wall -Wextra -Werror

# Flagi dla MiniLibX i systemu operacyjnego (macOS)
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

# Jeśli używasz Linuxa, zamień powyższe na to:
# MLX_FLAGS = -lmlx -lX11 -lXext -lm

# Kompilacja
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Reguła do kompilacji plików obiektowych
%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

# Czyszczenie plików obiektowych
clean:
	rm -f $(OBJS)

# Czyszczenie plików obiektowych i pliku wykonywalnego
fclean: clean
	rm -f $(NAME)

# Kompilacja na nowo
re: fclean all

# Specjalne reguły (nie dotyczą bezpośrednio plików)
.PHONY: all clean fclean re
