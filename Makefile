# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 11:43:35 by dmodrzej          #+#    #+#              #
#    Updated: 2024/10/23 19:47:57 by mbany            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

# compiler
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror

# sources
SRC_DIR =	srcs/
SRC		=	main.c engine.c graphics.c map.c messages.c utils.c
SRCS	=	$(addprefix $(SRC_DIR), $(SRC))

# objects
OBJ_DIR	=	objs/
OBJ		=	$(SRC:.c=.o)
OBJS	=	$(addprefix $(OBJ_DIR), $(OBJ))

# includes
INC		=	-I includes -I libs/libft -I libs/ft_printf -I libs/mlx

# libft
LIBFT_DIR	=	libs/libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_DIR)$(LIBFT_NAME)

# ft_printf
PRINT_F_DIR		=	libs/ft_printf/
PRINT_F_NAME	=	libftprintf.a
PRINT_F			=	$(PRINT_F_DIR)$(PRINT_F_NAME)

# mlx
MLX_DIR		=	libs/mlx/
MLX_NAME	=	libmlx.a
MLX			=	$(MLX_DIR)$(MLX_NAME)

# colors & symbols
GREEN 	= 	\033[0;32m
CYAN	=	\033[0;36m
NC		= 	\033[0m
TICK	=	✅

define PRINT_LOADING
	@printf "$(CYAN)["
	@for i in $$(seq 0 10 100); do \
		printf "▓"; \
		sleep 0.1; \
	done
	@printf "] 100%%$(RESET)\n"
endef

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
			@$(CC) $(FLAGS) -c $< -o $@ $(INC)

all:		$(LIBFT) $(PRINT_F) $(MLX) $(NAME)

$(NAME):	$(OBJS)
			@echo "$(CYAN)Compiling libs & program...$(NC)"
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINT_F) $(MLX) $(INC) -lXext -lX11 -lm
			@$(PRINT_LOADING)
			@echo "$(GREEN)Program compilation successful		$(TICK)$(NC)"

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(LIBFT):
			@make -sC $(LIBFT_DIR)

$(PRINT_F):
			@make -sC $(PRINT_F_DIR)

$(MLX):
			@make -sC $(MLX_DIR)

bonus:		$(LIBFT) $(PRINT_F) $(MLX) $(OBJS_BONUS)
			@echo "$(CYAN)Compiling libs & program...$(NC)"
			@$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME) $(LIBFT) $(PRINT_F) $(MLX) $(INC) -lXext -lX11 -lm
			@$(PRINT_LOADING)
			@echo "$(GREEN)Bonus program compilation successful		$(TICK)$(NC)"

clean:		
			@echo "$(CYAN)Cleaning .o files...$(NC)"
			@make clean -sC $(LIBFT_DIR)
			@make clean -sC $(PRINT_F_DIR)
			@make clean -sC $(MLX_DIR)
			@rm -rf $(OBJ_DIR)
			@$(PRINT_LOADING)
			@echo "$(GREEN)Cleaning of of .o files successful	$(TICK)$(NC)"

fclean:		clean
			@echo "$(CYAN)Cleaning libs & main program...$(NC)"
			@rm -f $(NAME) $(LIBFT) $(PRINT_F) $(MLX)
			@$(PRINT_LOADING)
			@echo "$(GREEN)Full cleaning successful		$(TICK)$(NC)"

re:			fclean all

.PHONY:		all clean fclean re