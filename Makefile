# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 17:45:04 by ahooghe           #+#    #+#              #
#    Updated: 2023/11/15 20:30:31 by ahooghe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3d

CC=gcc
CFLAGS=-Wall -Werror -Wextra

SRCS=srcs/main.c srcs/exit/free_exit.c srcs/init/init_data.c srcs/parsing/checkers.c srcs/parsing/parse_args.c srcs/parsing/parse_data.c

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