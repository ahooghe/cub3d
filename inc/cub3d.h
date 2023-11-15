/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:33:33 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/15 20:21:39 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

/*	**************************************************************************
										MACROS
	************************************************************************** */

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

/*	**************************************************************************
									ERROR MACROS
	************************************************************************** */

# define ERR_INP "Correct usage: ./cub3d <path to .cub file>"
# define ERR_FILE_IS_DIR "The path you entered is a directory."
# define ERR_FILE_NOT_CUB "The entered file does not have the .cub suffix."
# define ERR_FILE_NOT_XMP "The file does not contain valid .xmp textures."
# define ERR_MALLOC "Malloc failed."

/*	**************************************************************************
									ENUM
	************************************************************************** */

	enum e_output
	{
		SUCCESS = 0,
		FAILURE = 1,
	};

/*	**************************************************************************
									STRUCTS
	************************************************************************** */

typedef struct s_textureinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_textureinfo;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_eom;
}	t_mapinfo;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	int			**texture_pixels;
	int			**textures;
	t_textureinfo	texinfo;
	t_player	player;
	t_ray		ray;
	t_mapinfo	mapinfo;
	char		**map;
}	t_data;

/*	**************************************************************************
									FUNCTIONS
	************************************************************************** */

//init functions
void	init_data(t_data *data);

//exit functions
void	exit_cubed(t_data *data, int code);
int 	err_msg(char *str, int code);

//parse functions
int		parse_args(char *file, t_data *data);
int 	check_file(char *file, bool val);
void	parse_data(char *file, t_data *data);

//render functions
int	render(t_data *data);

//error handling functions

#endif