/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:42:32 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/18 22:37:17 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	print_ctrls(void)
{
	printf("\033[0;31m");
	printf("                                    .--,-``-.                 \n");
	printf("  ,----..                          /   /     '.      ,---,    \n");
	printf(" /   /   \\                ,---,   / ../        ;   .'  .' `\\  \n");
	printf("|   :     :         ,--,,---.'|   \\ ``\\  .`-    ',---.'     \\ \n");
	printf(".   |  ;. /       ,'_ /||   | :    \\___\\/   \\   :|   |  .`\\  |\n");
	printf(".   ; /--`   .--. |  | ::   : :         \\   :   |:   : |  '  |\n");
	printf(";   | ;    ,'_ /| :  . |:     |,-.      /  /   / |   ' '  ;  :\n");
	printf("|   : |    |  ' | |  . .|   : '  |      \\  \\   \\ '   | ;  .  |\n");
	printf(".   | '___ |  | ' |  | ||   |  / :  ___ /   :   ||   | :  |  '\n");
	printf("'   ; : .'|:  | : ;  ; |'   : |: | /   /\\   /   :'   : | /  ; \n");
	printf("'   | '/  :'  :  `--'   \\   | '/ :/ ,,/  ',-    .|   | '` ,/  \n");
	printf("|   :    / :  ,      .-./   :    |\\ ''\\        ; ;   :  .'    \n");
	printf(" \\   \\ .'   `--`----'   /    \\  /  \\   \\     .'  |   ,.'      \n");
	printf("  `---`                 `-'----'    `--`-,,-'    '---'        \n");
	printf("\n");
	printf("\033[1;34mCONTROLS:\n");
	printf("\033[0;36mW\033[0;37m: move forward\t");
	printf("\033[0;36mA\033[0;37m: move left\t");
	printf("\033[0;36mS\033[0;37m: move backward\t");
	printf("\033[0;36mD\033[0;37m: move right\n");
	printf("\033[0;36m<\033[0;37m: turn left\t");
	printf("\033[0;36m>\033[0;37m: turn right\n");
	printf("\033[0;36mESC\033[0;37m: quit\n");
}

int	err_msg(char *str, int code)
{
	ft_putendl_fd(str, 2);
	return (code);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (err_msg(ERR_INP, 1));
	init_data(&data);
	parse_args(argv[1], &data);
	init_mlx(&data);
	init_textures(&data);
	print_ctrls();
	input(&data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
