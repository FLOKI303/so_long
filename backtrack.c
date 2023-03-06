/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:13:32 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/06 10:38:59 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*get_pos(t_map map, char c, char **map1)
{
	int	*pos;
	int	i;
	int	j;

	i = 0;
	pos = malloc(2 * sizeof(int));
	if (!pos)
		return (0);
	while (map1[i])
	{
		j = 0;
		while (j < map.length)
		{
			if (map1[i][j] == c)
			{
				pos[0] = i;
				pos[1] = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	help_find_path(char **map, int i, int j, int *e_pos)
{
	if (i == e_pos[0] && j == e_pos[1])
		return (1);
	if (map[i][j] != '1')
	{
		map[i][j] = '1';
		if (help_find_path(map, i, j + 1, e_pos))
			return (1);
		if (help_find_path(map, i, j - 1, e_pos))
			return (1);
		if (help_find_path(map, i + 1, j, e_pos))
			return (1);
		if (help_find_path(map, i - 1, j, e_pos))
			return (1);
	}
	return (0);
}

static void	block_all_previous_collect(char **map1, int i, int **all_collect)
{
	int	j;

	j = 0;
	while (j < i)
	{
		map1[all_collect[j][0]][all_collect[j][1]] = '0';
		j++;
	}
}

static int	help_find_path_collect(t_map map, int *player_pos,
							int *exit_pos, int collect_number)
{
	int		*collect_pos;
	int		**all_collect;
	char	**map1;
	int		collect_fix;
	int		i;

	map1 = copy_map(map);
	collect_fix = collect_number;
	all_collect = malloc(collect_number * sizeof(all_collect));
	if (!all_collect)
		return (0);
	i = 0;
	while (collect_number--)
	{
		map1[exit_pos[0]][exit_pos[1]] = '1';
		collect_pos = get_pos(map, 'C', map1);
		all_collect[i] = malloc(2 * sizeof(int));
		all_collect[i][0] = collect_pos[0];
		all_collect[i][1] = collect_pos[1];
		if (!help_find_path(map1, player_pos[0], player_pos[1], collect_pos))
			return (0);
		map1 = copy_map(map);
		block_all_previous_collect(map1, ++i, all_collect);
	}
	return (1);
}

int	find_path(t_map map, int collect_number)
{
	int		*player_pos;
	int		*exit_pos;
	char	**map1;

	player_pos = get_pos(map, 'P', map.map);
	exit_pos = get_pos(map, 'E', map.map);
	if (!help_find_path_collect(map, player_pos, exit_pos, collect_number))
		return (0);
	map1 = copy_map(map);
	if (help_find_path(map1, player_pos[0], player_pos[1], exit_pos))
		return (1);
	return (0);
}
