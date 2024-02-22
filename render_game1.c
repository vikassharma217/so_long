/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:12:41 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/23 17:19:42 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_cell(t_game *data, t_img *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img, x * PIXEL, y
		* PIXEL);
}

void	draw_game(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_cell(data, &data->wall_img, x, y);
			else if (data->map[y][x] == 'C')
				draw_cell(data, &data->coll_img, x, y);
			else if (data->map[y][x] == 'P')
				draw_cell(data, &data->player_img, x, y);
			else if (data->map[y][x] == 'E')
				draw_cell(data, &data->exit_img, x, y);
			else if (data->map[y][x] == '0')
				draw_cell(data, &data->floor_img, x, y);
			x++;
		}
		y++;
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}
