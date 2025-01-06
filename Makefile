# Compilador e flags
CC = gcc
CFLAGS = -g -Wall

# Diretórios
LIBFT_DIR = libft
MLX_DIR = mlx
TESTS = tests
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = $(LIBFT_DIR)/include

# Arquivos fonte e objeto
SRC = tests/minilibx.c
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# Nome do executável principal
NAME = fdf

# Bibliotecas
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
LIBS = -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx -lm -lX11 -lXext

# Regras para o executável principal
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

$(OBJ_DIR)/%.o: $(TESTS)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(MLX_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re tests tests_clean tests_re started

# ======== TESTES ========
# Lista de arquivos de teste
FILES_TESTS = started_mlx.c
SRC_TESTS = $(addprefix $(TESTS)/, $(FILES_TESTS))
OBJ_TESTS = $(addprefix $(OBJ_DIR)/, $(FILES_TESTS:.c=.o))
BIN_TESTS = $(addprefix $(BIN_DIR)/, $(FILES_TESTS:.c=))

# Regra principal para compilar todos os testes
tests: $(BIN_TESTS)

# Regra para compilar cada binário de teste
$(BIN_DIR)/%: $(OBJ_DIR)/%.o $(LIBFT) $(MLX) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

# Regra para compilar objetos dos testes
$(OBJ_DIR)/%.o: $(TESTS)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(MLX_DIR) -c $< -o $@

# Criação dos diretórios necessários
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpeza dos arquivos de teste
tests_clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)

tests_re: tests_clean tests

