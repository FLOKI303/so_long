/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:19:53 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/04 11:54:12 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(int fd, int *map_length)
{
	char	*line;
	char	*prev_line;
	int		length;
	int		prev_length;
	int		lines_count;

	line = get_next_line(fd);
	prev_line = ft_strdup(line);
	length = ft_strlen(line);
	*map_length = length - 1;
	prev_length = length;
	lines_count = 0;
	while (line)
	{
		if (length != prev_length)
			return (free(line), free(prev_line), 0);
		prev_line = ft_strdup(line);
		line = get_next_line(fd);
		length = ft_strlen(line);
		if (line && line[length - 1] != '\n')
			prev_length--;
		lines_count++;
	}
	if (line && prev_line[prev_length - 1] == '\n')
		return (free(line), free(prev_line), 0);
	return (free(line), free(prev_line), lines_count);
}

int	check_line(char *str, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (str[i] != '1' && str[i] != '0'
			&& str[i] != 'C' && str[i] != 'E'
			&& str[i] != 'P')
			return (0);
		i++;
	}
	return (1);
}

static char	**fill_map(int fd, int lines_count, char **map, int length)
{
	char	*line;
	int		i;

	i = 0;
	while (lines_count--)
	{
		line = get_next_line(fd);
		if (!check_line(line, length))
			return (free(line), NULL);
		map[i] = ft_strdup(line);
		i++;
	}
	map[i] = 0;
	return (free(line), map);
}

char	**get_map(int fd, char *name, int *length, int *heigth)
{
	char	**map;
	int		lines_count;

	lines_count = count_lines(fd, length);
	if (!lines_count)
		return (0);
	*heigth = lines_count;
	reopen(fd, name);
	map = malloc((lines_count + 1) * sizeof(map));
	if (!map)
		return (0);
	map = fill_map(fd, lines_count, map, *length);
	return (map);
}
