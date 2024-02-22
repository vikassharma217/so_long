/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:34:06 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/23 17:13:28 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_event(t_game *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, exit_game, data);
	mlx_loop(data->mlx);
	free_map(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
}

void	error_message(const char *explicit_message)
{
	ft_printf("Error\n%s\n", explicit_message);
	exit(EXIT_FAILURE);
}

int	height_count(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	quit_game(t_game *data)
{
	int	moves;

	moves = data->moves;
	ft_printf("Total Moves: %d\n", moves);
	exit_game(data);
}
