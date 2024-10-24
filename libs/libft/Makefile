# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 19:45:42 by mbany             #+#    #+#              #
#    Updated: 2024/10/24 19:45:43 by mbany            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_strlen.c ft_strncmp.c \
			ft_bzero.c ft_memset.c ft_memcpy.c ft_tolower.c \
			ft_toupper.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_memmove.c ft_strchr.c ft_strrchr.c \
			ft_strnstr.c ft_memchr.c ft_memcmp.c ft_strlcpy.c \
			ft_strlcat.c ft_strdup.c ft_calloc.c ft_itoa.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_striteri.c ft_strmapi.c ft_lstadd_front.c ft_lstlast.c \
			ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_lstclear.c \
			ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_atoli.c \
			ft_strcmp.c get_next_line.c

OBJ_DIR =	obj

OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror

$(OBJ_DIR)/%.o: %.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean:
			@rm -rf $(OBJ_DIR)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
