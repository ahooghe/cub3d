/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:28:20 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/18 14:54:07 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

static int	fill_textures(t_textureinfo *texinfo, char *fileline, int j)
{
	if (fileline[j + 2] && !ft_isspace(fileline[j + 2]))
		return (ERR);
	if (fileline[j] == 'N' && fileline[j + 1] == 'O' && !(texinfo->north))
		texinfo->north = get_path(fileline, j + 2);
	else if (fileline[j] == 'S' && fileline[j + 1] == 'O' && !(texinfo->south))
		texinfo->south = get_path(fileline, j + 2);
	else if (fileline[j] == 'W' && fileline[j + 1] == 'E' && !(texinfo->west))
		texinfo->west = get_path(fileline, j + 2);
	else if (fileline[j] == 'E' && fileline[j + 1] == 'A' && !(texinfo->east))
		texinfo->east = get_path(fileline, j + 2);
	else
		return (ERR);
	return (SUCCESS);
}

static int	get_info(t_data *data, char **file, int i, int j)
{
	while (file[i][j] == ' ' || file[i][j] == '\t')
		j++;
	if (ft_isprint(file[i][j]) && !ft_isdigit(file[i][j]))
	{
		if (file[i][j + 1] && !ft_isspace(file[i][j + 1]) 
			&& !ft_isdigit(file[i][j]))
		{
			if (fill_textures(&data->texinfo, file[i], j) == ERR)
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
