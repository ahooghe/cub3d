/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:03:28 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/04 12:46:28 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	render(t_data *data)
{
	data->player.has_moved += move_player(data);
	init_texture_pixels(data);
	init_ray(&data->ray);
	raycaster(&data->player, data);
	render_frame(data);
	return (0);
}
