# Compilador e flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NODIR = --no-print-directory
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

# Colors
RESET   = \033[0m
RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
MAGENTA = \033[35m
CYAN    = \033[36m
WHITE   = \033[37m

# Regras para o executável principal
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)
	@echo "$(GREEN)$(NAME) compilado com sucesso!$(RESET)"

$(OBJ_DIR)/%.o: $(TESTS)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(MLX_DIR) -c $< -o $@

$(LIBFT):
	@echo "$(CYAN)Compilando Libft...$(RESET)"
	@make -C $(LIBFT_DIR) $(NODIR) 

$(MLX):
	@echo "$(CYAN)Compilando MLX...$(RESET)"
	@make -C $(MLX_DIR) > .mlx_mensages 2>&1
	@echo "$(GREEN)MLX compilado com sucesso$(RESET)"

clean:
	@echo "$(YELLOW)Clean LIBFT...$(RESET)"
	@make clean -C $(LIBFT_DIR) $(NODIR)
	@echo "$(YELLOW)Clean MLX...$(RESET)"
	@make clean -C $(MLX_DIR) $(NODIR) > .mlx_mensages 2>&1
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(CYAN)Objetos removidos.$(RESET)"

fclean: clean
	@rm -f $(LIBFT) 
	@rm -f $(NAME)
	@rm -rf $(BIN_DIR)
	@echo "$(GREEN)$(NAME) removido!$(RESET)"

re: fclean all

.PHONY: all clean fclean re tests tests_clean tests_re

# ======== TESTES ========
# Lista de arquivos de teste
FILES_TESTS = started_mlx.c pixel_put.c my_pixel_put.c triangulo.c events_init.c key_hook.c mouse_hook.c move_hook.c \
	      close_window.c paint.c loop_hook.c sync.c 
SRC_TESTS = $(addprefix $(TESTS)/, $(FILES_TESTS))
OBJ_TESTS = $(addprefix $(OBJ_DIR)/, $(FILES_TESTS:.c=.o))
BIN_TESTS = $(addprefix $(BIN_DIR)/, $(FILES_TESTS:.c=))

# Regra principal para compilar todos os testes
tests: $(BIN_TESTS)

# Regra para compilar cada binário de teste
$(BIN_DIR)/%: $(OBJ_DIR)/%.o $(LIBFT) $(MLX) | $(BIN_DIR)
	@echo "$(YELLOW)>>> Compilando binarios teste: $@$(RESET)"
	@$(CC) -g -o $@_test $< $(LIBS)

# Regra para compilar objetos dos testes
$(OBJ_DIR)/%.o: $(TESTS)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)>>> Compilando objetos teste: $@$(RESET)"
	@$(CC) -I$(INCLUDE_DIR) -I$(MLX_DIR) -c $< -o $@

# Criação dos diretórios necessários
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Limpeza dos arquivos de teste
tests_clean:
	@rm -f $(OBJ_TESTS)
	@rm -f $(BIN_TESTS)
	@echo "$(CYAN)Clean Tests$(RESET)"

tests_re: tests_clean tests


