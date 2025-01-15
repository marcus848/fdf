# Name
NAME = fdf

# Compile and Flags
CC = cc
CFLAGS = -Wall -Werror -Wextra
NODIR = --no-print-directory
INCLUDE = -Iinclude -lm -lXext -lX11

# Dirs
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
MLX_DIR = mlx
TESTS_DIR = tests
BIN_DIR = bin
APP_DIR = app

# Libs
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/init_structs.c \
       $(SRC_DIR)/init_utils.c \
       $(SRC_DIR)/error.c \
       $(SRC_DIR)/coordinates.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Colors
RESET   = \033[0m
RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
MAGENTA = \033[35m
CYAN    = \033[36m
WHITE   = \033[37m

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)Done!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_DIR) $(NODIR)

$(MLX):
	@echo "Building MLX..."
	@make -C $(MLX_DIR)

clean:
	@echo "Cleaning up object files..."
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) 
	@make clean -C $(MLX_DIR)

fclean: clean
	@echo "Removing binary..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

# ======== TESTES ========
# Lista de arquivos de teste
FILES_TESTS = started_mlx.c pixel_put.c my_pixel_put.c triangulo.c events_init.c key_hook.c mouse_hook.c move_hook.c \
	      close_window.c paint.c loop_hook.c sync.c 
SRC_TESTS = $(addprefix $(TESTS_DIR)/, $(FILES_TESTS))
OBJ_TESTS = $(addprefix $(OBJ_DIR)/, $(FILES_TESTS:.c=.o))
BIN_TESTS = $(addprefix $(BIN_DIR)/, $(FILES_TESTS:.c=))

# Regra principal para compilar todos os testes
tests: $(BIN_TESTS)

# Regra para compilar cada binário de teste
$(BIN_DIR)/%: $(OBJ_DIR)/%.o $(LIBFT) $(MLX) | $(BIN_DIR)
	@echo "$(YELLOW)>>> Compilando $@...$(RESET)"
	@$(CC) -g -o $@_test $< $(LIBFT) $(MLX) $(INCLUDE)

# Regra para compilar objetos dos testes
$(OBJ_DIR)/%.o: $(TESTS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -I$(LIBFT_DIR)/include -I$(MLX_DIR) -c $< -o $@

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Limpeza dos arquivos de teste
tests_clean:
	@rm -f $(BIN_DIR)/*test
	@echo "$(CYAN)Clean Tests$(RESET)"

tests_re: tests_clean tests

