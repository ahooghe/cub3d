/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:12:38 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/04 12:54:31 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Initialise img struct elements to NULL
void	init_img_clean(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

//Change the xpm files to images in mlx format
static void	init_texture_img(t_data *data, t_img *img, char *filepath)
{
	init_img_clean(img);
	img->img = mlx_xpm_file_to_image(data->mlx, filepath, \
			&data->texinfo.size, &data->texinfo.size);
	if (!img->img)
		exit_cubed(data, err_msg(ERR_MLX_IMG, FAILURE));
	img->addr = (int *)mlx_get_data_addr(img->img, &img->pixel_bits, \
	&img->size_line, &img->endian);
}

//Convert the mlx images to int arrays
static int	*xpm_to_img(t_data *data, char *filepath)
{
	t_img	img;
	int		*addr;
	int		x;
	int		y;

	init_texture_img(data, &img, filepath);
	addr = ft_calloc(1, sizeof(*(addr)) * \
			data->texinfo.size * data->texinfo.size);
	if (!addr)
		exit_cubed(data, err_msg(ERR_MALLOC, FAILURE));
	y = 0;
	while (y < data->texinfo.size)
	{
		x = 0;
		while (x < data->texinfo.size)
		{
			addr[y * data->texinfo.size + x] = \
				img.addr[y * data->texinfo.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img.img);
	return (addr);
}

//Initialise the textures
void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof(*(data->textures)));
	if (!data->textures)
		exit_cubed(data, err_msg(ERR_MALLOC, FAILURE));
	data->textures[NORTH] = xpm_to_img(data, data->texinfo.north);
	data->textures[SOUTH] = xpm_to_img(data, data->texinfo.south);
	data->textures[EAST] = xpm_to_img(data, data->texinfo.east);
	data->textures[WEST] = xpm_to_img(data, data->texinfo.west);
}
