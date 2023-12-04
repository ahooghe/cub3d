/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:12:30 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/04 12:30:34 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Handle key presses
static int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		exit_cubed(data, SUCCESS);
	if (keycode == XK_w)
		data->player.move_y = 1;
	if (keycode == XK_s)
		data->player.move_y = -1;
	if (keycode == XK_a)
		data->player.move_x = -1;
	if (keycode == XK_d)
		data->player.move_x = 1;
	if (keycode == XK_Left)
		data->player.rotate -= 1;
	if (keycode == XK_Right)
		data->player.rotate += 1;
	return (0);
}

//Handle key releases
static int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		exit_cubed(data, SUCCESS);
	if (keycode == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	if (keycode == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	if (keycode == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	if (keycode == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (keycode == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (keycode == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

//Handle exit for mlx hook
int	exit_cub3d(t_data *data)
{
	exit_cubed(data, SUCCESS);
	return (SUCCESS);
}

void	input(t_data *data)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, exit_cub3d, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release, data);
}
