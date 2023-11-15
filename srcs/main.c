/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:42:32 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/15 20:28:01 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int err_msg(char *str, int code)
{
    ft_putendl_fd(str, 2);
    return (code);
}

int main(int argc, char **argv)
{
    t_data data;
    
    if (argc != 2)
        return (err_msg(ERR_INP, 1));
    init_data(&data);
    parse_args(argv[1], &data);
    //init_mlx(&data);
    //init_textures(&data);
    //print_ctrls();
    //input(&data);
    //mlx_loop_hook(data.mlx, render, &data);
    //mlx_loop(data.mlx);
    return (0);
}