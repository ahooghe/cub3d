/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:20:46 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/18 22:35:16 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Check if the string is a number
static bool	ft_isnumber(char *str)
{
	int		i;
	bool	digit;

	i = 0;
	digit = true;
	while (ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (false);
	while (str[i] && !ft_isspace(str[i]))
	{
		if (ft_isdigit(str[i]) == 0)
			digit = false;
		i++;
	}
	return (digit);
}

//Convert the string to an int array
static int	*ft_stoia(char **rgb_split, int *rgb)
{
	int	i;

	i = 0;
	while (rgb_split[i])
	{
		if (ft_isnumber(rgb_split[i]) == true)
			rgb[i] = ft_atoi(rgb_split[i]);
		else
		{
			free_2dim((void **)rgb_split);
			free(rgb);
			return (0);
		}
		i++;
	}
	free_2dim((void **)rgb_split);
	return (rgb);
}

//Set the rgb values
static int	*set_rgb(t_data *data, char *colors)
{
	char	**rgb_split;
	int		*rgb;
	int		i;

	rgb_split = ft_split(colors, ',');
	if (rgb_split == NULL)
		exit_cubed(data, err_msg(ERR_MALLOC, 0));
	i = 0;
	while (rgb_split[i])
		i++;
	if (i != 3)
		free_2dim((void **)rgb_split);
	if (i != 3)
		return (0);
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		exit_cubed(data, err_msg(ERR_MALLOC, 0));
	return (ft_stoia(rgb_split, rgb));
}

int	fill_color(t_data *data, t_textureinfo *texinfo, char *fileline, int j)
{
	if (fileline[j + 1] && !ft_isspace(fileline[j + 1]))
		return (err_msg(ERR_FLOOR_CEILING, ERR));
	if (!texinfo->ceiling && fileline[j] == 'C')
	{
		texinfo->ceiling = set_rgb(data, fileline + j + 1);
		if (texinfo->ceiling == 0)
			return (err_msg(ERR_CEILING, ERR));
	}
	else if (!texinfo->floor && fileline[j] == 'F')
	{
		texinfo->floor = set_rgb(data, fileline + j + 1);
		if (texinfo->floor == 0)
			return (err_msg(ERR_FLOOR, ERR));
	}
	else
		return (err_msg(ERR_FLOOR_CEILING, ERR));
	return (SUCCESS);
}
