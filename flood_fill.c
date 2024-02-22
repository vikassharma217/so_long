/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:32:42 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/23 16:38:49 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_check(t_game *data, int x, int y, int *coins)
{
	if (x <= 0 || y <= 0 || y >= data->map_height || x >= data->map_width
		|| data->map[y][x] == '1' || data->map[y][x] == 'c'
		|| data->map[y][x] == 'o' || data->map[y][x] == 'e'
		|| data->map[y][x] == 'E')
	{
		if (data->map[y][x] == 'E')
		{
			data->map[y][x] = 'e';
			data->exitcheck = 1;
		}
		return ;
	}
	if (data->map[y][x] == 'C')
	{
		(*coins)--;
		data->map[y][x] = 'c';
	}
	else if (data->map[y][x] == '0')
		data->map[y][x] = 'o';
	flood_fill_check(data, x - 1, y, coins);
	flood_fill_check(data, x + 1, y, coins);
	flood_fill_check(data, x, y - 1, coins);
	flood_fill_check(data, x, y + 1, coins);
}

void	ft_reset(t_game *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'c')
				data->map[y][x] = 'C';
			else if (data->map[y][x] == 'e')
				data->map[y][x] = 'E';
			else if (data->map[y][x] == 'o')
				data->map[y][x] = '0';
			x++;
		}
		y++;
	}
}
