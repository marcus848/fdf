# File name
NAME = libft.a

# flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Dirs
SRC_DIR = src
OBJ_DIR = obj

# Submodules
CHAR_DIR = $(SRC_DIR)/char
IO_DIR = $(SRC_DIR)/io
STRING_DIR = $(SRC_DIR)/string
LIST_DIR = $(SRC_DIR)/list
MEMORY_DIR = $(SRC_DIR)/memory
PRINTF_DIR = $(SRC_DIR)/ft_printf
GNL_DIR = $(SRC_DIR)/gnl

# Colors
RESET   = \033[0m
RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
MAGENTA = \033[35m
CYAN    = \033[36m
WHITE   = \033[37m

# Files
SRCS = \
	$(CHAR_DIR)/ft_isalnum.c \
	$(CHAR_DIR)/ft_isalpha.c \
	$(CHAR_DIR)/ft_isascii.c \
	$(CHAR_DIR)/ft_isdigit.c \
	$(CHAR_DIR)/ft_isprint.c \
	$(CHAR_DIR)/ft_tolower.c \
	$(CHAR_DIR)/ft_toupper.c \
	$(IO_DIR)/ft_putchar_fd.c \
	$(IO_DIR)/ft_putendl_fd.c \
	$(IO_DIR)/ft_putnbr_fd.c \
	$(IO_DIR)/ft_putstr_fd.c \
	$(IO_DIR)/ft_putnstr_fd.c \
	$(LIST_DIR)/ft_lstadd_back.c \
	$(LIST_DIR)/ft_lstadd_front.c \
	$(LIST_DIR)/ft_lstclear.c \
	$(LIST_DIR)/ft_lstdelone.c \
	$(LIST_DIR)/ft_lstiter.c \
	$(LIST_DIR)/ft_lstlast.c \
	$(LIST_DIR)/ft_lstmap.c \
	$(LIST_DIR)/ft_lstnew.c \
	$(LIST_DIR)/ft_lstsize.c \
	$(MEMORY_DIR)/ft_bzero.c \
	$(MEMORY_DIR)/ft_calloc.c \
	$(MEMORY_DIR)/ft_memchr.c \
	$(MEMORY_DIR)/ft_memcmp.c \
	$(MEMORY_DIR)/ft_memcpy.c \
	$(MEMORY_DIR)/ft_memmove.c \
	$(MEMORY_DIR)/ft_memset.c \
	$(MEMORY_DIR)/ft_realloc.c \
	$(STRING_DIR)/ft_atoi.c \
	$(STRING_DIR)/ft_atoi_base.c \
	$(STRING_DIR)/ft_itoa.c \
	$(STRING_DIR)/ft_split.c \
	$(STRING_DIR)/ft_strchr.c \
	$(STRING_DIR)/ft_strdup.c \
	$(STRING_DIR)/ft_striteri.c \
	$(STRING_DIR)/ft_strjoin.c \
	$(STRING_DIR)/ft_strlcat.c \
	$(STRING_DIR)/ft_strlcpy.c \
	$(STRING_DIR)/ft_strlen.c \
	$(STRING_DIR)/ft_strmapi.c \
	$(STRING_DIR)/ft_strncmp.c \
	$(STRING_DIR)/ft_strnstr.c \
	$(STRING_DIR)/ft_strrchr.c \
	$(STRING_DIR)/ft_strtrim.c \
	$(STRING_DIR)/ft_substr.c \
	$(STRING_DIR)/ft_count_words.c \
	$(PRINTF_DIR)/ft_printf.c \
	$(PRINTF_DIR)/parse_format.c \
	$(PRINTF_DIR)/parse_utils.c \
	$(PRINTF_DIR)/free_specifiers.c \
	$(PRINTF_DIR)/print_format.c \
	$(PRINTF_DIR)/print_format_utils.c \
	$(PRINTF_DIR)/printf_i_d_u.c \
	$(PRINTF_DIR)/printf_i_d_u_utils.c \
	$(PRINTF_DIR)/printf_p_x.c \
	$(PRINTF_DIR)/printf_p_x_utils.c \
	$(PRINTF_DIR)/printf_s_c_percent.c \
	$(GNL_DIR)/get_next_line.c

# Objects
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Main rules
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) criado com sucesso.$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(CYAN)Objetos removidos.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME) removido.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
