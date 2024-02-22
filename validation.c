/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:46:16 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/23 17:15:18 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_check(t_game *data)
{
	int		x;
	int		y;
	int		count;
	char	**map;

	map = data->map;
	x = 0;
	count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'E')
				count++;
			y++;
		}
		x++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	collectible_check(t_game *data)
{
	int		x;
	int		y;
	int		count;
	char	**map;

	map = data->map;
	x = 0;
	count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				count++;
			y++;
		}
		x++;
	}
	if (count < 1)
		return (0);
	return (1);
}

int	start_check(t_game *data)
{
	int		x;
	int		y;
	int		count;
	char	**map;

	map = data->map;
	x = 0;
	count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				count++;
			}
			y++;
		}
		x++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	boundry_check(t_game *data)
{
	int	x;

	x = 0;
	while (x < data->map_height)
	{
		if (data->map[x][0] != '1' || data->map[x][data->map_width - 1] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (x < data->map_height)
	{
		if (data->map[x][0] != '1' || data->map[x][data->map_width - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	char_check(t_game *data)
{
	int		x;
	int		y;
	int		height;
	int		width;
	char	**map;

	x = 0;
	height = data->map_height;
	width = data->map_width;
	map = data->map;
	while (map[x] && x < height)
	{
		y = 0;
		while (map[x][y] && y < width)
		{
			if (map[x][y] != '0' && map[x][y] != '1' && map[x][y] != 'C'
				&& map[x][y] != 'P' && map[x][y] != 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
