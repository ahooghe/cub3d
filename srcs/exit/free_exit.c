/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:18:32 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/18 16:18:33 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Function to free a 2 dimensional array
void	free_2dim(void **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

//Function to free the textureinfo struct
static void	free_texinfo(t_textureinfo *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->east)
		free(textures->east);
	if (textures->west)
		free(textures->west);
	if (textures->floor)
		free(textures->floor);
	if (textures->ceiling)
		free(textures->ceiling);
}

//Function to free the map struct
static void	free_map(t_data *data)
{
	if (data->mapinfo.fd > 0)
		close(data->mapinfo.fd);
	if (data->mapinfo.file)
		free_2dim((void **)data->mapinfo.file);
	if (data->map)
		free_2dim((void **)data->map);
}

//Function to free the data struct
static int	free_data(t_data *data)
{
	if (data->textures)
		free_2dim((void **)data->textures);
	if (data->texture_pixels)
		free_2dim((void **)data->texture_pixels);
	free_texinfo(&data->texinfo);
	free_map(data);
	return (1);
}

//Function to close mlx and exit without leaks
void	exit_cubed(t_data *data, int code)
{
	if (!data)
		exit(code);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	free_data(data);
	exit(code);
}
