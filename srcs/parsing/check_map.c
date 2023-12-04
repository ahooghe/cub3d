/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:18:43 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/04 11:46:07 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Checks if the map is surrounded by walls
static int	check_map_border(t_mapinfo *mapinfo, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapinfo->height)
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == (mapinfo->height - 1))
				if (map[i][j] != '1')
					return (FAILURE);
			if (j == 0 || map[i][j + 1] == '\0')
				if (map[i][j] != '1')
					return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

//Checks if the map contains only valid characters
static int	check_map_content(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(ft_strchr("01NSEW", map[i][j])))
				return (err_msg(ERR_MAP_INVALID, FAILURE));
			if (ft_strchr("NSEW", map[i][j]) && data->player.dir == '\0')
			{
				data->player.dir = map[i][j];
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
			}
			else if (ft_strchr("NSEW", map[i][j]) && data->player.dir != '\0')
				return (err_msg(ERR_TOO_MANY_PLAYERS, FAILURE));
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

//Checks if the player is surrounded by has valid pathing
static int	check_player_pos(t_data *data, char **map)
{
	int	i;
	int	j;

	if (data->player.dir == '\0')
		return (err_msg(ERR_NO_PLAYER, FAILURE));
	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map[i - 1]) < (size_t)j || ft_strlen(map[i + 1]) < (size_t)j)
		return (FAILURE);
	return (SUCCESS);
}

//Checks if the map is the last element in the file
static int	check_map_is_eof(t_mapinfo *map)
{
	int	i;
	int	j;

	i = map->index_eom;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (!ft_isspace(map->file[i][j]))
				return (err_msg(ERR_MAP_NOT_LAST, FAILURE));
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_data *data, char **map)
{
	if (!data->map)
		return (err_msg(ERR_NO_MAP, FAILURE));
	if (check_map_border(&data->mapinfo, map) == FAILURE)
		return (err_msg(ERR_NO_WALL_WRAP, FAILURE));
	if (data->mapinfo.height < 3 || data->mapinfo.width < 3)
		return (err_msg(ERR_MAP_TOO_SMALL, FAILURE));
	if (check_map_content(data, map) == FAILURE)
		return (FAILURE);
	if (check_player_pos(data, map) == FAILURE)
		return (FAILURE);
	if (check_map_is_eof(&data->mapinfo) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
