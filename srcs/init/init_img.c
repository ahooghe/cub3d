#include "../../inc/cub3d.h"

void    init_img(t_data *data)
{
    data->img.img = mlx_new_image(data->mlx, data->win_width, data->win_height);
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.pixel_bits, &data->img.size_line, &data->img.endian);
}