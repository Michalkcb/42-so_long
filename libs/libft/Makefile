# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Library name
NAME = libft.a

# Source files (here should land all other c libraries seperated with space)
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c \
		ft_strlen.c ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_printchar.c ft_printf.c ft_printnbr.c ft_printp.c ft_printstr.c\
		ft_strmapi.c ft_striteri.c ft_split.c

# Object files
OBJS = $(SRCS:.c=.o)

# Lib builder
LIBC = ar rcs

# Main compiling rule
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# Main rule for compiling the library
$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

# Rule for cleaning object files
clean:
	rm -f $(OBJS)

# Rule for fully cleaning the project (removing executable and object files)
fclean: clean
	rm -f $(NAME)

# Default rule
all: $(NAME)

# Recompile all
re: fclean all

# Phony targets to avoid conflicts with file names
.PHONY: all re clean fclean
