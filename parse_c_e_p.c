/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c_e_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:12:03 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/07 12:03:26 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectibles(t_map map)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (map.map[++i])
	{
		j = 0;
		if (i != 0 && map.map[i][map.length] == '\n')
		{
			while (map.map[i][j])
			{
				if (j != 0 && j < map.length - 1)
				{
					if (map.map[i][j] == 'C')
						count++;
				}
				j++;
			}
		}
	}
	return (count);
}

int	check_player_exit(t_map map, char c)
{
	int		i;
	int		j;
	int		exit;

	i = -1;
	exit = 0;
	while (map.map[++i])
	{
		j = 0;
		if (i != 0 && map.map[i][map.length] == '\n')
		{
			while (map.map[i][j])
			{
				if (j != 0 && j < map.length - 1)
				{
					if (map.map[i][j] == c)
						exit ++;
				}
				j++;
			}
		}
	}
	return (exit);
}

int	check_exit(t_map map)
{
	return (check_player_exit(map, 'E'));
}

int	check_player(t_map map)
{
	return (check_player_exit(map, 'P'));
}
