/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:31:08 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/23 17:16:46 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_check(t_game *data)
{
	int	x;
	int	y;
	int	coins;

	data->exitcheck = 0;
	coins = count_coins(data);
	cur_location(data->map, &x, &y);
	flood_fill_check(data, x, y, &coins);
	if (coins != 0 || data->exitcheck == 0)
	{
		return (0);
	}
	ft_reset(data);
	return (1);
}

int	rectangular_map_check(t_game *data)
{
	int		i;
	int		count;
	char	**map;

	map = data->map;
	i = 1;
	count = ft_strlength(map[0]);
	while (map[i])
	{
		if (ft_strlength(map[i]) != count)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_map(t_game *data)
{
	if (exit_check(data) && collectible_check(data) && start_check(data)
		&& boundry_check(data) && char_check(data) && path_check(data)
		&& rectangular_map_check(data))
		return (1);
	return (0);
}
