# Variables #

NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -rf

# Libraries #

LIBFT_DIR		= lib/libft
LIBFT_FILE		= $(LIBFT_DIR)/libft.a

MLX_DIR			= lib/minilibx-linux
MLX_FILE		= $(MLX_DIR)/libmlx.a

MAKE_LIB		= make --no-print-directory -C

# Push swap sources #

SO_LONG_SRC	= $(wildcard *.c)

# Push swap objects #

SO_LONG_OBJ = $(addprefix obj/, $(SO_LONG_SRC:.c=.o))

# Rules #

all: $(NAME)

$(LIBFT_FILE):
	@$(MAKE_LIB) $(LIBFT_DIR)

$(MLX_FILE):
	@$(MAKE_LIB) $(MLX_DIR)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_FILE) $(MLX_FILE) $(SO_LONG_OBJ)
	$(CC) $(SO_LONG_OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -o $(NAME) -lX11 -lXext
	@echo $(NAME) compiled!

clean:
	@$(RM) obj
	@$(RM) $(LIBFT_DIR)/*.o
	@$(RM) $(LIBFT_DIR)/.DS_Store
	@$(RM) $(LIBFT_DIR)/.vscode
	@echo Objects removed

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_FILE)
	@$(MAKE_LIB) $(MLX_DIR) clean
	@$(RM) .vscode
	@$(RM) .DS_Store
	@echo Executable removed

re: fclean all

.PHONY: all clean fclean re