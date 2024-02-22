/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:46:44 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/23 17:11:02 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_resources(t_game *data)
{
	data->wall_img = load_image(data->mlx, data->wall);
	data->floor_img = load_image(data->mlx, data->floor);
	data->coll_img = load_image(data->mlx, data->coll);
	data->player_img = load_image(data->mlx, data->player);
	data->exit_img = load_image(data->mlx, data->exit);
	if (!data->wall_img.img || !data->floor_img.img || !data->coll_img.img
		|| !data->player_img.img || !data->exit_img.img)
	{
		error_message("Failed to load textures");
	}
}

t_img	load_image(void *mlx, char *file)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, file, &img.width, &img.height);
	if (img.img == NULL)
	{
		error_message("Error loading texture");
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

int	key_hook(int key, t_game *data)
{
	if (key == ESC)
	{
		exit_game(data);
	}
	else if (key == W || key == A || key == S
		|| key == D)
	{
		execute_move(key, data);
	}
	return (0);
}
