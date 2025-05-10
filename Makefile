# Nazwa programu
NAME        = so_long

# Kompilator i flagi
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I includes -I includes/libft

# Biblioteka libft
LIBFT_DIR   = includes/libft
LIBFT       = $(LIBFT_DIR)/libft.a

# MinilibX
MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -lXext -lX11

# Pliki źródłowe
SRC_DIR     = src
SRC_FILES   = main.c parser.c parser2.c flood_fill.c

# Pliki obiektowe (w katalogu głównym)
OBJ_FILES   = $(SRC_FILES:.c=.o)

# Reguła: kompilacja .c -> .o
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Domyślna kompilacja
all: $(LIBFT) $(MLX_LIB) $(NAME)

# Budowanie libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Budowanie minilibX
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Linkowanie programu
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

# Czyszczenie plików obiektowych i libft
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ_FILES)

# Pełne czyszczenie (bin + obiekty + biblioteki)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

# Odbudowa od zera
re: fclean all

.PHONY: all clean fclean re