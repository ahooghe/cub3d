/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:18:41 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/18 16:18:42 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Parsing the file data into the data struct and its appropriate sub classes
int	parse_args(char *file, t_data *data)
{
	if (check_file(file, true) == FAILURE)
		exit_cubed(data, FAILURE);
	parse_data(file, data);
	if (get_file_data(data, data->mapinfo.file) == FAILURE)
		exit_cubed(data, FAILURE);
	if (check_map(data, data->map) == FAILURE)
		exit_cubed(data, FAILURE);
	if (check_textures(data, &data->texinfo) == FAILURE)
		exit_cubed(data, FAILURE);
	init_player_direction(data);
	return (SUCCESS);
}
