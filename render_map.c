/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:26:45 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/23 17:38:56 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(char *str)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_message("ERROR ! CANNOT OPEN MAP");
	height = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		free(line);
		error_message("ERROR ! GNL");
	}
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	return (height);
}

int	map_width(char *map_path)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_message("ERROR ! CANNOT OPEN MAP");
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	width = ft_strlength(line) - 1;
	free(line);
	close(fd);
	return (width);
}

char	**init_map(char *map_path)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;
	int		height;

	height = map_height(map_path);
	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_message("ERROR ! MAP CAN NOT BE OPNED");
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
		error_message("ERROR ! MEMORY ALLOCATION FAILED");
	line = get_next_line(fd);
	while (i < height && line != NULL)
	{
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map[i] = NULL;
	return (map);
}
