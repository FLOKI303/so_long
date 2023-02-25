/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:13:32 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/24 19:50:49 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*get_pos(struct s_map map, char c)
{
	int	*pos;
	int	i;
	int	j;

	i = 0;
	pos = malloc(2 * sizeof(int));
	while (map.map[i])
	{
		j = 0;
		while(j < map.length)
		{
			if (map.map[i][j] == c)
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

char	**copy_map(struct s_map map)
{
	char	**map1;
	int		i;
	int		j;

	i = 0;
	map1 = malloc((map.heigth + 1) * sizeof(map1));
	if (!map1)
		return (0);
	while (map.map[i])
	{
		j = 0;
		map1[i] = malloc((map.length + 1) * sizeof(char *));
		if (!map1[i])
			return (0);
		while (map.map[i][j])
		{
			map1[i][j] = map.map[i][j];
			j++;
		}
		map1[i][j] = '\0';
		i++;
	}
	map1[i] = 0;
	return (map1);
}

int	help_find_path(char **map, int i, int j, int *e_pos)
{
	ft_printf("i: %d\n", i);
	ft_printf("j: %d\n", j);
	ft_printf("\n");
	if (i == e_pos[0] && j == e_pos[1])
		return(1);
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

int	find_path(struct s_map map)
{
	int		*player_pos;
	int		*exit_pos;
	char	**map1;

	player_pos = get_pos(map, 'P');
	exit_pos = get_pos(map, 'E');
	// for (int i = 0; i < 2; i++)
	// 	ft_printf(" p %d\n", player_pos[i]);
	// for (int i = 0; i < 2; i++)
	// 	ft_printf(" e %d\n", exit_pos[i]);
	map1 = copy_map(map);
	if (help_find_path(map1, player_pos[0], player_pos[1], exit_pos))
		return (1);
	return (0);
}