/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:25:26 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/23 16:58:56 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlength(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	cur_location(char **map, int *x, int *y)
{
	int	i;
	int	j;
	int	map_width;
	int	map_height;

	map_height = height_count(map);
	map_width = ft_strlength(map[0]);
	i = 0;
	while (i <= map_height)
	{
		j = 0;
		while (j <= map_width)
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	free_map(map);
}

int	count_coins(t_game *data)
{
	int		i;
	int		j;
	int		coins;
	char	**map;

	map = data->map;
	i = 0;
	coins = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}

void	move_player(int new_x, int new_y, char **map, t_game *data)
{
	int	coll_collected;
	int	current_x;
	int	current_y;

	coll_collected = 0;
	cur_location(map, &current_x, &current_y);
	data->total_coll = count_coins(data);
	if (map[new_y][new_x] != '1')
	{
		if (map[new_y][new_x] == 'E')
		{
			if (coll_collected == data->total_coll)
				quit_game(data);
			else
				return ;
		}
		if (map[new_y][new_x] == 'C')
			coll_collected++;
		map[current_y][current_x] = '0';
		map[new_y][new_x] = 'P';
		data->moves++;
	}
}

void	execute_move(int keycode, t_game *data)
{
	int	x;
	int	y;

	cur_location(data->map, &x, &y);
	if (keycode == W)
	{
		move_player(x, y - 1, data->map, data);
	}
	else if (keycode == A)
	{
		move_player(x - 1, y, data->map, data);
	}
	else if (keycode == S)
	{
		move_player(x, y + 1, data->map, data);
	}
	else if (keycode == D)
	{
		move_player(x + 1, y, data->map, data);
	}
	ft_printf("Moves: %d\n", data->moves);
	draw_game(data);
}
