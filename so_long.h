/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:12:47 by msumon            #+#    #+#             */
/*   Updated: 2023/12/23 17:21:57 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define PIXEL 35

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		map_height;
	int		map_width;
	int		moves;
	int		exitcheck;
	char	**map;
	char	*map_path;
	char	*wall;
	char	*floor;
	char	*coll;
	char	*player;
	char	*exit;
	int		total_coll;
	t_img	floor_img;
	t_img	wall_img;
	t_img	coll_img;
	t_img	player_img;
	t_img	exit_img;
}			t_game;

char		**init_map(char *map_path);
void		free_map(char **map);
void		execute_move(int keycode, t_game *data);
void		cur_location(char **map, int *x, int *y);
t_img		load_image(void *mlx, char *file);
int			key_hook(int keycode, t_game *data);
void		quit_game(t_game *data);
void		draw_game(t_game *data);
void		set_event(t_game *data);
void		load_resources(t_game *data);
int			height_count(char **map);
int			ft_strlength(char *str);
void		initialize_mlx(t_game *data);
int			exit_game(t_game *data);
int			map_height(char *str);
int			map_width(char *map_path);

int			count_coins(t_game *data);
void		error_message(const char *explicit_message);

int			exit_check(t_game *data);
int			collectible_check(t_game *data);
int			start_check(t_game *data);
int			rectangular_map_check(t_game *data);
int			char_check(t_game *data);
int			boundry_check(t_game *data);
int			path_check(t_game *data);
int			is_valid_map(t_game *data);
void		flood_fill_check(t_game *data, int x, int y, int *coins);
void		ft_reset(t_game *data);

#endif
