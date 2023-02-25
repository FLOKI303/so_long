/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c_e_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:12:03 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/25 16:02:24 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectibles(struct s_map map)
{
	int		i;
	int		j;
	char	**map1;
	int		count;

	i = 0;
	count = 0;
	map1 = map.map;
	while (map1[i])
	{
		j = 0;
		if (i != 0 && map1[i][map.length] == '\n')
		{
			while (map1[i][j])
			{
				if (j != 0 && j < map.length - 1)
				{
					if (map1[i][j] == 'C')
						count++;
				}
				j++;
			}
		}
		i++;
	}
	return (count);
}

int	check_player_exit(struct s_map map, char c)
{
	int		i;
	int		j;
	int		exit;
	char	**map1;

	map1 = map.map;
	i = -1;
	exit = 0;
	while (map1[++i])
	{
		j = 0;
		if (i != 0 && map1[i][map.length] == '\n')
		{
			while (map1[i][j])
			{
				if (j != 0 && j < map.length - 1)
				{
					if (map1[i][j] == c)
						exit ++;
				}
				j++;
			}
		}
	}
	return (exit);
}

int	check_exit(struct s_map map)
{
	return (check_player_exit(map, 'E'));
}

int	check_player(struct s_map map)
{
	return (check_player_exit(map, 'P'));
}
