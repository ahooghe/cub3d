/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <brmajor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:45:07 by brmajor           #+#    #+#             */
/*   Updated: 2023/11/23 12:45:08 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void    raycaster(t_player *plyr, t_data *data)
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
}