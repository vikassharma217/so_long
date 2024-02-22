/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:42:48 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/23 17:34:20 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *data)
{
	free_map(data->map);
	mlx_destroy_image(data->mlx, data->exit_img.img);
	mlx_destroy_image(data->mlx, data->floor_img.img);
	mlx_destroy_image(data->mlx, data->coll_img.img);
	mlx_destroy_image(data->mlx, data->player_img.img);
	mlx_destroy_image(data->mlx, data->wall_img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_printf("CONGRATULATIONS :)\n");
	exit(0);
	return (0);
}

void	initialize_mlx(t_game *data)
{
	int	win_height;
	int	win_width;

	win_height = data->map_height * PIXEL;
	win_width = data->map_width * PIXEL;
	if (win_height <= 1080 && win_width <= 1920)
	{
		data->mlx_win = mlx_new_window(data->mlx, win_width, win_height,
				"./so_long");
		if (!data->mlx_win)
		{
			error_message("ERROR ! WINDOW FAILED");
		}
	}
	else
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_map(data->map);
		error_message("ERROR ! MAP IS TOO BIG");
	}
}

void	game_start(t_game *data)
{
	if (is_valid_map(data) == 1)
	{
		initialize_mlx(data);
		load_resources(data);
		draw_game(data);
		set_event(data);
	}
	else
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_map(data->map);
		error_message("INVALID MAP !!!");
	}
}

void	value_assign(t_game *data)
{
	data->moves = 0;
	data->wall = "./textures/wall.xpm";
	data->floor = "./textures/background.xpm";
	data->coll = "./textures/collectibles.xpm";
	data->player = "./textures/player.xpm";
	data->exit = "./textures/end.xpm";
	data->map_height = map_height(data->map_path);
	data->map_width = map_width(data->map_path);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		error_message("INVALID ARGUMENTS");
	data.map_path = argv[1];
	value_assign(&data);
	data.map = init_map(data.map_path);
	//printf("%s\n", data.map_path);
	if (!(data.map))
	{
		free_map(data.map);
		error_message("INVALID MAP");
	}
	data.mlx = mlx_init();
	if (!data.mlx)
		error_message("MLX FAILED");
	game_start(&data);
	return (0);
}
