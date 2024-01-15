NAME = so_long
SRCS = so_long.c map_check.c move.c utils.c check.c map.c utils2.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

MINILIBX = ./mlx/libmlx.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror -I ./mlx -L ./mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS)
	@make -C ./mlx
	@$(CC) $(CFLAGS) $(SRCS) $(MINILIBX) -o $(NAME)
	@echo "The game is ready!"

clean:
	@make clean -C ./mlx
	@rm -f $(OBJ)
	@rm -rf so_long.dSYM
	@echo "Object files removed!"

fclean: clean
	@make clean -C ./mlx
	@rm -f $(NAME)
	@rm -rf so_long.dSYM
	@echo "The game is removed!"

re: fclean all

.PHONY: all clean fclean re bonus
