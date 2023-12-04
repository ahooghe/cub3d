/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:45:07 by brmajor           #+#    #+#             */
/*   Updated: 2023/12/03 20:48:19 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*void    raycaster(t_player *plyr, t_data *data)
{
	int     x;
	t_ray   ray;

	x = 0;
	while (x < data->win_width)
	{
		ray.camera_x = 2 * x / (double)data->win_width - 1;
		ray.dir_x = plyr->dir_x + plyr->plane_x * ray.camera_x;
		ray.dir_y = plyr->dir_y + plyr->plane_y * ray.camera_x;
		ray.map_x = (int)plyr->pos_x;
		ray.map_y = (int)plyr->pos_y;
		ray.deltadist_x = fabs(1 / ray.dir_x);
		ray.deltadist_y = fabs(1 / ray.dir_y);
		ray.side = 0;
		if (ray.dir_x < 0)
		{
			ray.step_x = -1;
			ray.sidedist_x = (plyr->pos_x - ray.map_x) * ray.deltadist_x;
		}
		else
		{
			ray.step_x = 1;
			ray.sidedist_x = (ray.map_x + 1.0 - plyr->pos_x) * ray.deltadist_x;
		}
		if (ray.dir_y < 0)
		{
			ray.step_y = -1;
			ray.sidedist_y = (plyr->pos_y - ray.map_y) * ray.deltadist_y;
		}
		else
		{
			ray.step_y = 1;
			ray.sidedist_y = (ray.map_y + 1.0 - plyr->pos_y) * ray.deltadist_y;
		}
		while (ray.side == 0)
		{
			if (ray.sidedist_x < ray.sidedist_y)
			{
				ray.sidedist_x += ray.deltadist_x;
				ray.map_x += ray.step_x;
				ray.side = 0;
			}
			else
			{
				ray.sidedist_y += ray.deltadist_y;
				ray.map_y += ray.step_y;
				ray.side = 1;
			}
			if (data->map[ray.map_x][ray.map_y] == '1')
				ray.side = 2;
		}
		if (ray.side == 0)
			ray.wall_dist = (ray.map_x - plyr->pos_x + (1 - ray.step_x) / 2) / ray.dir_x;
	}
}*/
static void	init_raycaster_info(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1; //Your code :]
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

static void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0) //Your code :]
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

static void	perform_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > data->mapinfo.height - 0.25
			|| ray->map_x > data->mapinfo.width - 1.25)
			break ;
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}

static void	calculate_line_height(t_ray *ray, t_data *data, t_player *player)
{
	if (ray->side == 0) // If the ray is facing a horizontal wall
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else // If the ray is facing a vertical wall
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(data->win_height / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + data->win_height / 2;
	if (ray->draw_start < 0) // So we dont draw out of bounds
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

static void get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->texinfo.index = WEST;
		else
			data->texinfo.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->texinfo.index = SOUTH;
		else
			data->texinfo.index = NORTH;
	}
}

static void	update_textures(t_data *data, t_textureinfo *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(data, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - data->win_height / 2 + ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end) // Looping through every pixel that we should draw and setting the colour of said pixel
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711; // Create a shadow-esque effect on the NORHT and EAST walls by shifting the colours to a darker state and layering black over them (7F7F7F = 8355711 = 01111111 01111111 01111111)
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}

void raycaster(t_player *plyr, t_data *data)
{
	t_ray	tempray;
	int     x;

	x = 0;
	while (x < data->win_width)
	{
		init_raycaster_info(x, &tempray, plyr);
		set_dda(&tempray, plyr);
		perform_dda(data, &tempray);
		calculate_line_height(&tempray, data, plyr);
		update_textures(data, &data->texinfo, &tempray, x);
		x++;
	}
}