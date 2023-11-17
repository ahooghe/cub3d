/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:50:48 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/16 13:12:05 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Will read in the whole file to check how many lines
//	are in the file for the mallocation
static int	get_amount_lines(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_cubed(data, err_msg(strerror(errno), errno));
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

//Fill the 2 dimensional array in data with the file data
static void	fill_2dim(int row, int column, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->mapinfo.fd);
	while (line != NULL)
	{
		data->mapinfo.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->mapinfo.file[row])
			exit_cubed(data, err_msg(ERR_MALLOC, SUCCESS));
		while (line[i] != '\0')
			data->mapinfo.file[row][column++] = line[i++];
		data->mapinfo.file[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->mapinfo.fd);
	}
	data->mapinfo.file[row] = NULL;
}

//Mallocing and assigning the data struct to store the file data correctly
void	parse_data(char *file, t_data *data)
{
	data->mapinfo.line_count = get_amount_lines(data, file);
	data->mapinfo.path = file;
	data->mapinfo.file = ft_calloc(data->mapinfo.line_count + 1,
			sizeof(char *));
	if (!(data->mapinfo.file))
		exit_cubed(data, err_msg(ERR_MALLOC, 0));
	data->mapinfo.fd = open(file, O_RDONLY);
	if (data->mapinfo.fd < 0)
		exit_cubed(data, err_msg(strerror(errno), FAILURE));
	fill_2dim(0, 0, 0, data);
	close (data->mapinfo.fd);
	data->mapinfo.fd = -1;
}
