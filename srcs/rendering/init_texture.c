/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <brmajor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:44:58 by brmajor           #+#    #+#             */
/*   Updated: 2023/11/23 12:46:54 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void    init_texture_pixels(t_data *data)
{
    int     i;
    int     j;

    i = 0;
    data->texture_pixels = malloc(sizeof(int *) * 4);
    if (!data->texture_pixels)
        exit(1);
    while (i < 4)
    {
        data->texture_pixels[i] = malloc(sizeof(int) * (data->texinfo.tex_height * data->texinfo.tex_width));
        if (!data->texture_pixels[i])
            exit(1);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < (data->texinfo.tex_height * data->texinfo.tex_width))
        {
            data->texture_pixels[i][j] = data->textures[i][j];
            j++;
        }
        i++;
    }
}