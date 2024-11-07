# Variables #
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -g
RM = rm -rf

# Libraries #
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR			= lib/minilibx-linux
MLX_FILE		= $(MLX_DIR)/libmlx.a

MAKE_LIB = make --no-print-directory

# So long sources #
SO_LONG_SRC = main.c map_validation.c validations.c validations_utils.c

# So long objects #
SO_LONG_OBJ = $(addprefix obj/, $(SO_LONG_SRC:.c=.o))

all: $(NAME)

$(LIBFT):
	@$(MAKE_LIB) -C $(LIBFT_DIR)

#$(MLX_FILE):
#	@$(MAKE_LIB) $(MLX_DIR)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SO_LONG_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(SO_LONG_OBJ) -L$(LIBFT_DIR) -lft
	@echo "$(NAME) created!"

clean:
	@$(RM) obj
	@$(RM) $(LIBFT_DIR)/obj
	@$(RM) $(LIBFT_DIR)/.DS_Store
	@$(RM) $(LIBFT_DIR)/.vscode
	@echo Objects removed

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)/libft.a

re: fclean all

.PHONY: all clean fclean re
