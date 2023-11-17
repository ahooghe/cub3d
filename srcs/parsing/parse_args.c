/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:07:08 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/16 13:25:14 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Parsing the file data into the data struct and its appropriate sub classes
int parse_args(char *file, t_data *data)
{
	if (check_file(file, true) == FAILURE)
		exit_cubed(data, FAILURE);
	parse_data(file, data);
	//if (get_file_data(data, data->mapinfo.file) == FAILURE)
		//exit_cubed(data, FAILURE);
	//if (check_map(data, data->map) == FAILURE)
	//    exit_cubed(data, FAILURE);
	//if (check_textures_validity(data, &data->texinfo) == FAILURE)
	//    exit_cubed(data, FAILURE);
	init_player_direction(data);
	return (SUCCESS);
}
