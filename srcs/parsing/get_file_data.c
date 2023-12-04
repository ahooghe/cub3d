/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:28:20 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/04 12:45:33 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Get the path of the texture
static char	*get_path(char *fileline, int j)
{
	int		len;
	int		i;
	char	*path;

	while (fileline[j] && ft_isspace(fileline[j]))
		j++;
	len = j;
	while (fileline[j] && !ft_isspace(fileline[j]))
		j++;
	path = malloc(sizeof(char) * j - len + 1);
	if (!path)
		return (NULL);
	i = 0;
	while (fileline[len] && !ft_isspace(fileline[len]))
		path[i++] = fileline[len++];
	path[i] = '\0';
	while (fileline[len] && ft_isspace(fileline[len]))
		len++;
	if (fileline[len] && fileline[len] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

// Assign the given texture to the right element of the struct
static int	fill_textures(t_data *data, t_textureinfo *tex, char *file, int j)
{
	if (file[j + 2] && !ft_isspace(file[j + 2]))
		return (ERR);
	if (file[j] == 'N' && file[j + 1] == 'O' && !(tex->north))
		tex->north = get_path(file, j + 2);
	else if (file[j] == 'S' && file[j + 1] == 'O' && !(tex->south))
		tex->south = get_path(file, j + 2);
	else if (file[j] == 'W' && file[j + 1] == 'E' && !(tex->west))
		tex->west = get_path(file, j + 2);
	else if (file[j] == 'E' && file[j + 1] == 'A' && !(tex->east))
		tex->east = get_path(file, j + 2);
	else if ((tex->north) && (tex->south) && (tex->west) && \
		(tex->east))
		exit_cubed(data, err_msg(ERR_TOO_MANY_TEXTURES, FAILURE));
	else
		return (ERR);
	return (SUCCESS);
}

// Extract the info from the file and fill the struct
static int	get_info(t_data *data, char **file, int i, int j)
{
	while (ft_isspace(file[i][j]))
		j++;
	if (ft_isprint(file[i][j]) && !ft_isdigit(file[i][j]))
	{
		if (file[i][j + 1] && !ft_isspace(file[i][j + 1]) \
			&& !ft_isdigit(file[i][j]))
		{
			if (fill_textures(data, &data->texinfo, file[i], j) == ERR)
				return (err_msg(ERR_TEX_INVALID, FAILURE));
			return (BREAK);
		}
		else
		{
			if (fill_color(data, &data->texinfo, file[i], j) == ERR)
				return (FAILURE);
			return (BREAK);
		}
	}
	else if (ft_isdigit(file[i][j]))
	{
		if (create_map(data, file, i) == FAILURE)
			return (err_msg(ERR_INVALID_MAP, FAILURE));
		return (SUCCESS);
	}
	return (CONTINUE);
}

// Get the data from the file line by line
int	get_file_data(t_data *data, char **file)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			ret = get_info(data, file, i, j);
			if (ret == FAILURE)
				return (FAILURE);
			else if (ret == SUCCESS)
				return (SUCCESS);
			else if (ret == BREAK)
				break ;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
