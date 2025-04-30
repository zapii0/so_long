# Nazwa programu
NAME = so_long

# Kompilator i flagi
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Iincludes/libft

# Pliki źródłowe
SRC = src/main.c \
      src/parsing/parsing.c \
      src/rendering/map_rendering.c \
      src/input/input.c

OBJ = $(SRC:.c=.o)

# Libft
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Kompilacja
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lminilibx-linux -lmlx -lXext -lX11 -o $(NAME)

# Czyszczenie
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
