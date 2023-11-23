/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <brmajor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:45:12 by brmajor           #+#    #+#             */
/*   Updated: 2023/11/23 12:45:13 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void    render_frame(t_data *data)
{
    int     x;
    int     y;
    int     tex_x;
    int     tex_y;
    int     color;

    x = 0;
    while (x < data->win_width)
    {
        y = 0;
        while (y < data->win_height)
        {
            tex_x = (int)(data->ray.wall_x * (double)data->texinfo.tex_width);
            if (data->ray.side == 0 && data->ray.dir_x > 0)
                tex_x = data->texinfo.tex_width - tex_x - 1;
            if (data->ray.side == 1 && data->ray.dir_y < 0)
                tex_x = data->texinfo.tex_width - tex_x - 1;
            tex_y = (int)(y * 2 - data->win_height + data->ray.line_height) * (data->texinfo.tex_height / 2) / data->ray.line_height;
            color = data->texture_pixels[data->ray.side][data->texinfo.tex_width * tex_y + tex_x];
            if (data->ray.side == 1)
                color = (color >> 1) & 8355711;
            data->img.addr[y * data->win_width + x] = color;
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}