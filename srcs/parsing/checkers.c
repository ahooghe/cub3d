/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:14:30 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/18 16:00:32 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Function to check if file is a dir
static bool	is_dir(char *file)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = true;
	}
	return (ret);
}

//Function to check if  file is .cub
static bool	is_cub(char *file)
{
	size_t	len;
	char	*sub;

	len = ft_strlen(file);
	sub = ft_substr(file, len - 4, 4);
	if (ft_strncmp(sub, ".cub", 4) == 0)
		return (true);
	return (false);
}

//Function to check if file is .xmp
static bool	is_xpm(char *file)
{
	size_t	len;
	char	*sub;

	len = ft_strlen(file);
	sub = ft_substr(file, len - 4, 4);
	if (ft_strncmp(sub, ".xpm", 4) == 0)
		return (true);
	return (false);
}

//Function to check if file is file
int	check_file(char *file, bool val)
{
	int		fd;

	if (is_dir(file))
		return (err_msg(ERR_FILE_IS_DIR, FAILURE));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (err_msg(strerror(errno), FAILURE));
	close(fd);
	if (val && !is_cub(file))
		return (err_msg(ERR_FILE_NOT_CUB, FAILURE));
	if (!val && !is_xpm(file))
		return (err_msg(ERR_FILE_NOT_XPM, FAILURE));
	return (SUCCESS);
}
