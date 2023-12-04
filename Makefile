NAME=cub3d

CC=cc
CFLAGS=-Wall -Werror -Wextra -g

SRCS=srcs/main.c
SRCS_PARSING=srcs/parsing/checkers.c srcs/parsing/parse_args.c srcs/parsing/parse_data.c srcs/parsing/get_file_data.c srcs/parsing/color.c srcs/parsing/create_map.c srcs/parsing/check_map.c srcs/parsing/check_textures.c
SRCS_EXIT=srcs/exit/free_exit.c
SRCS_INIT=srcs/init/init_data.c srcs/init/init_texture.c srcs/init/init_mlx.c
SRCS_MOVEMENT=srcs/movement_handling/init_player_direction.c srcs/movement_handling/input.c srcs/movement_handling/move.c
SRCS_DEBUG=srcs/debug/debug.c
SRCS_RENDER=srcs/rendering/renderer.c srcs/rendering/init_texture.c srcs/rendering/raycaster.c srcs/rendering/render_frame.c
all: 
	@echo "\033[0;33mCompiling libraries..\033[0m"
	@make -sC libft > /dev/null
	@make -sC minilibx-linux > /dev/null 2>&1
	@echo "\033[0;33mCompiling Cub3D..\033[0m"
	@$(CC) $(CCFLAGS) -o $(NAME) $(SRCS) $(SRCS_PARSING) $(SRCS_EXIT) $(SRCS_INIT) $(SRCS_MOVEMENT) $(SRCS_DEBUG) $(SRCS_RENDER) -Llibft libft/libft.a -Lminilibx-linux minilibx-linux/libmlx.a -lX11 -lXext -lm -lbsd
	@echo "\033[0;32mCompilation Succesful! You can now execute using ./$(NAME) <map.cub>\033[0m"

clean:
	@echo "\033[0;31mRemoving all .o files..\033[0m"
	@make -sC libft clean > /dev/null
	@make -sC minilibx-linux clean > /dev/null 2>&1
	@rm -rf *.o
	@echo "\033[0;31m.o files removed.\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving all archive files and the executable..\033[0m"
	@make -C libft fclean > /dev/null
	@rm -rf $(NAME)
	@echo "\033[0;31mExecutable file and library archives have been removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re
