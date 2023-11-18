/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:33:33 by ahooghe           #+#    #+#             */
/*   Updated: 2023/11/18 22:16:22 by ahooghe          ###   ########.fr       */
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

# define TEX_SIZE 64

# define MOVESPEED 0.015
# define ROTSPEED 0.015

/*	**************************************************************************
									ERROR MACROS
	************************************************************************** */

# define ERR_INP "Correct usage: ./cub3d <path to .cub file>"
# define ERR_FILE_IS_DIR "The path you entered is a directory."
# define ERR_FILE_NOT_CUB "The entered file does not have the .cub suffix."
# define ERR_FILE_NOT_XPM "The file does not contain valid .xpm textures."
# define ERR_MALLOC "Malloc failed."
# define ERR_TEX_INVALID "Texture file is invalid."
# define ERR_TOO_MANY_TEXTURES "There are too many texture files."
# define ERR_INVALID_MAP "Map structure is invalid."
# define ERR_FLOOR_CEILING "Formatting of floor and/or ceiling is wrong."
# define ERR_FLOOR "Floor is not a valid RGB color."
# define ERR_CEILING "Ceiling is not a valid RGB color."
# define ERR_RGB "Input color is not a valid RGB color."
# define ERR_DIR "The direction inside the given map is invalid."
# define ERR_NO_MAP "No map found in file."
# define ERR_NO_WALL_WRAP "The given map is not surrounded by walls."
# define ERR_MAP_TOO_SMALL "The given map is too small."
# define ERR_MAP_INVALID "The given map has characters that don't exist."
# define ERR_TOO_MANY_PLAYERS "The given map has more than 1 player."
# define ERR_MAP_NOT_LAST "The map is not the last element in the file."
# define ERR_NO_PLAYER "The map does not contain a player."
# define ERR_MISSING_TEXTURE "The file does not contain all textures."
# define ERR_MISSING_COLOR "The file does not contain all colors."
# define ERR_COLOR_INVALID "Invalid RGB value."
# define ERR_MLX_START "Mlx failed to start."
# define ERR_MLX_WIN "Mlx failed to create a window."
# define ERR_MLX_IMG "Mlx failed to create an image."

/*	**************************************************************************
									ENUM
	************************************************************************** */

	enum e_output
	{
		SUCCESS = 0,
		FAILURE = 1,
		ERR = 2,
		BREAK = 3,
		CONTINUE = 10,
	};

	enum e_side
	{
		NORTH = 0,
		SOUTH = 1,
		WEST = 2,
		EAST = 3,
	};

/*	**************************************************************************
									STRUCTS
	************************************************************************** */

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;
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
void	init_mlx(t_data *data);
void	init_textures(t_data *data);
void	init_img_clean(t_img *img);

//exit functions
void	exit_cubed(t_data *data, int code);
int 	err_msg(char *str, int code);
void	free_2dim(void **arr);

//parse functions
int		parse_args(char *file, t_data *data);
int 	check_file(char *file, bool val);
void	parse_data(char *file, t_data *data);
int		get_file_data(t_data *data, char **file);
int 	fill_color(t_data *data, t_textureinfo *texinfo, char *fileline, int j);
int		create_map(t_data *data, char **file, int i);
int 	check_map(t_data *data, char **map);
int		check_textures(t_data *data, t_textureinfo *texinfo);

//render functions
int	render(t_data *data);

//movement functions
void	input(t_data *data);
void	init_player_direction(t_data *data);
int		move_player(t_data *data);

//debug function
void	debug_data(t_data *data);


#endif