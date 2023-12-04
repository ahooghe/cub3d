/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:47:18 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/04 12:35:56 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Functions to initialise all structs to 0 / NULL values
//	for easier debugging and freeing

void	init_texture(t_textureinfo *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->floor = 0;
	texture->ceiling = 0;
	texture->hex_floor = 0x0;
	texture->hex_ceiling = 0x0;
	texture->size = TEX_SIZE;
	texture->index = 0;
	texture->step = 0.0;
	texture->pos = 0.0;
	texture->x = 0;
	texture->y = 0;
}

void	init_map(t_mapinfo *map)
{
	map->fd = 0;
	map->line_count = 0;
	map->path = NULL;
	map->file = NULL;
	map->height = 0;
	map->width = 0;
	map->index_eom = 0;
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0.0;
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0.0;
	ray->sidedist_y = 0.0;
	ray->deltadist_x = 0.0;
	ray->deltadist_y = 0.0;
	ray->wall_dist = 0.0;
	ray->wall_x = 0.0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_player(t_player *player)
{
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	data->texture_pixels = NULL;
	data->textures = NULL;
	init_img_clean(&data->img);
	init_texture(&data->texinfo);
	init_player(&data->player);
	init_ray(&data->ray);
	init_map(&data->mapinfo);
	data->map = NULL;
}
