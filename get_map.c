/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:19:53 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/07 12:39:41 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_last_line(char *line, int length, int *prev_length)
{
	if (line && line[length - 1] != '\n')
			(*prev_length)--;
}

static int	count_lines(int fd, int *map_length)
{
	char	*line;
	unsigned int		length;
	int		lines_count;
	int		check;

	check = 1;
	lines_count = 0;
	line = NULL;
	while (line || check)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		if (check)
		{
			length = ft_strlen(line);
			*map_length = length - 1;
			check = 0;
		}
		if (ft_strlen(line) == length - 1 && line[length - 2] != '\n')
			break ;
		else if (length != ft_strlen(line))
			return (free(line), 0);
		free(line);
		lines_count++;
	}
	return (free(line), lines_count + 1);
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
	int		check;
	int		i;

	i = 0;
	check  = 0;
	while (lines_count--)
	{
		if (check)
			free(line);
		line = get_next_line(fd);
		check = 1;
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
	ft_printf("|%d|", *length);
	map = fill_map(fd, lines_count, map, *length);
	return (map);
}
