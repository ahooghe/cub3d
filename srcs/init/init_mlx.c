/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:07:55 by brmajor           #+#    #+#             */
/*   Updated: 2023/11/18 20:42:05 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Initialize mlx
void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_cubed(data, err_msg(ERR_MLX_START, FAILURE));
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		exit_cubed(data, err_msg(ERR_MLX_WIN, FAILURE));
}
