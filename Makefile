NAME=cub3d

CC=gcc
CFLAGS=-Wall -Werror -Wextra

SRCS=srcs/main.c srcs/exit/free_exit.c srcs/init/init_data.c srcs/parsing/checkers.c srcs/parsing/parse_args.c srcs/parsing/parse_data.c srcs/parsing/get_file_data.c srcs/parsing/color.c srcs/parsing/create_map.c srcs/parsing/check_map.c srcs/parsing/check_textures.c srcs/movement_handling/init_player_direction.c srcs/debug/debug.c

all: 
	make -sC libft
	make -sC minilibx-linux
	$(CC) $(CCFLAGS) -o $(NAME) $(SRCS) -Llibft libft/libft.a -Lminilibx-linux minilibx-linux/libmlx.a -lX11


clean:
	make -sC libft clean
	make -sC minilibx-linux clean
	@rm -rf *.o

fclean: clean
	make -C libft fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
