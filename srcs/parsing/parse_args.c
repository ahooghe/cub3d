#include "../../inc/cub3d.h"

//Parsing the file data into the data struct and its appropriate sub classes
int parse_args(char *file, t_data *data)
{
	if (check_file(file, true) == FAILURE)
		exit_cubed(data, FAILURE);
	parse_data(file, data);
	if (get_file_data(data, data->mapinfo.file) == FAILURE)
		exit_cubed(data, FAILURE);
	//if (check_map(data, data->map) == FAILURE)
	//    exit_cubed(data, FAILURE);
	//if (check_textures_validity(data, &data->texinfo) == FAILURE)
	//    exit_cubed(data, FAILURE);
	//init_player_direction(data);
	return (SUCCESS);
}
