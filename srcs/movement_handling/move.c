/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:16:19 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/04 12:45:05 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Check if the new position is valid
static int	is_valid_pos(t_data *data, double x, double y)
{
	if (data->map[(int)y][(int)x] == '1' || data->map[(int)y][(int)x] == '\0')
		return (FAILURE);
	if (x < 0.25 || x >= data->mapinfo.width - 1.25)
		return (FAILURE);
	if (y < 0.25 || y >= data->mapinfo.height -0.25)
		return (FAILURE);
	return (SUCCESS);
}

// If the new position is valid, update the player position
static int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, data->player.pos_y) == SUCCESS && \
		is_valid_pos(data, data->player.pos_x, new_y) == SUCCESS)
	{
		data->player.pos_x = new_x;
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}

// Move the player position
static int	move_player_pos(t_data *data)
{
	double	new_x;
	double	new_y;

	if (data->player.move_y == 1)
	{
		new_x = data->player.pos_x + data->player.dir_x * MOVESPEED;
		new_y = data->player.pos_y + data->player.dir_y * MOVESPEED;
	}
	else if (data->player.move_y == -1)
	{
		new_x = data->player.pos_x - data->player.dir_x * MOVESPEED;
		new_y = data->player.pos_y - data->player.dir_y * MOVESPEED;
	}
	else if (data->player.move_x == -1)
	{
		new_x = data->player.pos_x + data->player.dir_y * MOVESPEED;
		new_y = data->player.pos_y - data->player.dir_x * MOVESPEED;
	}
	else if (data->player.move_x == 1)
	{
		new_x = data->player.pos_x - data->player.dir_y * MOVESPEED;
		new_y = data->player.pos_y + data->player.dir_x * MOVESPEED;
	}
	return (validate_move(data, new_x, new_y));
}

// Rotate the player
static int	rotate_player(t_data *data)
{
	double		rot;
	double		tmp_x;

	tmp_x = data->player.dir_x;
	rot = ROTSPEED * data->player.rotate;
	data->player.dir_x = data->player.dir_x * cos(rot) - \
		data->player.dir_y * sin(rot);
	data->player.dir_y = tmp_x * sin(rot) + data->player.dir_y * cos(rot);
	tmp_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rot) - \
		data->player.plane_y * sin(rot);
	data->player.plane_y = tmp_x * sin(rot) + data->player.plane_y * cos(rot);
	return (1);
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += move_player_pos(data);
	if (data->player.move_y == -1)
		moved += move_player_pos(data);
	if (data->player.move_x == -1)
		moved += move_player_pos(data);
	if (data->player.move_x == 1)
		moved += move_player_pos(data);
	if (data->player.rotate != 0)
		moved += rotate_player(data);
	return (moved);
}
