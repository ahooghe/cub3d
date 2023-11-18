#include "../../inc/cub3d.h"

static unsigned long	convert_rgb_to_hex(int *rgb)
{
	unsigned long	result;

	result = (unsigned long)((rgb[0] & 0xff) * 65536) + ((rgb[1] & 0xff) * 256) + (rgb[2] & 0xff);
	return (result);
}

static int	check_valid_rgb(int *rgb)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (err_msg(ERR_COLOR_INVALID, FAILURE));
		i++;
	}
	return (SUCCESS);
}

int	check_textures(t_data *data, t_textureinfo *texinfo)
{
	if (!texinfo->north || !texinfo->south || !texinfo->west || !texinfo->east)
		return (err_msg(ERR_MISSING_TEXTURE, FAILURE));
	if (!texinfo->floor || !texinfo->ceiling)
		return (err_msg(ERR_MISSING_COLOR, FAILURE));
	if (check_file(texinfo->north, false) == FAILURE ||
		check_file(texinfo->south, false) == FAILURE ||
		check_file(texinfo->west, false) == FAILURE ||
		check_file(texinfo->east, false) == FAILURE)
		return (FAILURE);
	if (check_valid_rgb(texinfo->floor) == FAILURE ||
		check_valid_rgb(texinfo->ceiling) == FAILURE)
		return (FAILURE);
	texinfo->hex_floor = convert_rgb_to_hex(texinfo->floor);
	texinfo->hex_ceiling = convert_rgb_to_hex(texinfo->ceiling);
	return (SUCCESS);
}
