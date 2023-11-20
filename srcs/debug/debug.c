/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:18:22 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/18 16:18:23 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	debug_text(t_textureinfo *texinfo)
{
	printf("%s\n", texinfo->north);
	printf("%s\n", texinfo->south);
	printf("%s\n", texinfo->west);
	printf("%s\n", texinfo->east);
	printf("%lu\n", texinfo->hex_floor);
	printf("%lu\n", texinfo->hex_ceiling);
}

static void	debug_map(t_mapinfo *mapinfo)
{
	int	i;

	i = 0;
	printf("%d\n", mapinfo->fd);
	printf("%d\n", mapinfo->line_count);
	printf("%s\n", mapinfo->path);
	printf("%d\n", mapinfo->height);
	printf("%d\n", mapinfo->width);
	printf("%d\n", mapinfo->index_eom);
	while (i < mapinfo->line_count)
		printf("%s\n", mapinfo->file[i++]);
}

static void	debug_ray(t_ray *ray)
{
	printf("%f\n", ray->camera_x);
	printf("%f\n", ray->dir_x);
	printf("%f\n", ray->dir_y);
	printf("%d\n", ray->map_x);
	printf("%d\n", ray->map_y);
	printf("%d\n", ray->step_x);
	printf("%d\n", ray->step_y);
	printf("%f\n", ray->sidedist_x);
	printf("%f\n", ray->sidedist_y);
	printf("%f\n", ray->deltadist_x);
	printf("%f\n", ray->deltadist_y);
	printf("%f\n", ray->wall_dist);
	printf("%f\n", ray->wall_x);
	printf("%d\n", ray->side);
	printf("%d\n", ray->line_height);
	printf("%d\n", ray->draw_start);
	printf("%d\n", ray->draw_end);
}

static void	debug_player(t_player *player)
{
	printf("%c\n", player->dir);
	printf("%f\n", player->pos_x);
	printf("%f\n", player->pos_y);
}

void	debug_data(t_data *data)
{
	int	i;

	i = 0;
	printf("TEXTURE STRUCT:\n");
	debug_text(&data->texinfo);
	printf("MAP STRUCT:\n");
	debug_map(&data->mapinfo);
	printf("RAY STRUCT:\n");
	debug_ray(&data->ray);
	printf("PLAYER STRUCT:\n");
	debug_player(&data->player);
	printf("MAP:\n");
	while (i < data->mapinfo.height)
		printf("%s\n", data->map[i++]);
}
