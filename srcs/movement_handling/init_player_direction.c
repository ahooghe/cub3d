/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:21:17 by brmajor           #+#    #+#             */
/*   Updated: 2023/11/18 20:39:16 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Set the starting position of the player
static void	playernorthsouth(t_data *data)
{
	if (data->player.dir == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.plane_x = 0.5;
		data->player.plane_y = 0;
	}
	else if (data->player.dir == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.plane_x = -0.5;
		data->player.plane_y = 0;
	}
}

static void	playereastwest(t_data *data)
{
	if (data->player.dir == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = 0.5;
	}
	else if (data->player.dir == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -0.5;
	}
}

void	init_player_direction(t_data *data)
{
	if (data->player.dir == 'N' || data->player.dir == 'S')
		playernorthsouth(data);
	else if (data->player.dir == 'E' || data->player.dir == 'W')
		playereastwest(data);
	else
		exit_cubed(data, err_msg(ERR_DIR, FAILURE));
}
