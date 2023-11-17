/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:20:46 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/16 13:22:05 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int fill_color(t_data *data, t_textureinfo *texinfo, char *fileline, int j)
{
    if (fileline[j + 1] && !ft_isspace(fileline[j + 1]))
        return (err_msg(ERR_FLOOR_CEILING, ERR));
    if (!texinfo->ceiling && fileline[j] == 'C')
    {
        
    }
    else if (!texinfo->floor && fileline[j] == 'F')
    {
        
    }
    else
        return (err_msg(ERR_FLOOR_CEILING, ERR));
    return (SUCCESS);
}