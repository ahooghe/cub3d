/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:54:58 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/04 11:45:40 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Find the biggest line in the map
static size_t	find_biggest_line(t_mapinfo *mapinfo, int index)
{
	size_t	biggest_len;

	biggest_len = ft_strlen((const char *)mapinfo->file[index]);
	while (mapinfo->file[index])
	{
		if (ft_strlen(mapinfo->file[index]) > biggest_len)
			biggest_len = ft_strlen(mapinfo->file[index]);
		index++;
	}
	return (biggest_len);
}

// Count the number of lines in the map
static int	count_map_lines(t_data *data, char **file, int i)
{
	int	k;
	int	l;

	k = i;
	while (file[k])
	{
		l = 0;
		while (ft_isspace(file[k][l]))
			l++;
		if (file[k][l] != '1' && file[k][l] != '0')
			break ;
		k++;
	}
	data->mapinfo.index_eom = k;
	return (k - i);
}

// Fill the map with the data from the file
static int	fill_map(t_data *data, t_mapinfo *mapinfo, char **map, int index)
{
	int	i;
	int	j;

	mapinfo->width = find_biggest_line(mapinfo, index);
	i = 0;
	while (i < mapinfo->height)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * mapinfo->width + 1);
		if (!map[i])
			exit_cubed(data, err_msg(ERR_MALLOC, FAILURE));
		while (mapinfo->file[index][j] && mapinfo->file[index][j] != '\n')
		{
			map[i][j] = mapinfo->file[index][j];
			j++;
		}
		while (j < mapinfo->width)
			map[i][j++] = '\0';
		i++;
		index++;
	}
	map[i] = NULL;
	return (SUCCESS);
}

// Replace the spaces in the map with '1'
static void	fill_map_whitespace(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_isspace(data->map[i][j]))
				data->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	create_map(t_data *data, char **file, int i)
{
	data->mapinfo.height = count_map_lines(data, file, i);
	data->map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->map)
		exit_cubed(data, err_msg(ERR_MALLOC, FAILURE));
	if (fill_map(data, &data->mapinfo, data->map, i) == FAILURE)
		return (FAILURE);
	fill_map_whitespace(data);
	printf("\n");
	return (SUCCESS);
}
