/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:45:31 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/23 14:38:29 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_first_and_last_1(char *str, int length)
{
	if (str[0] == '1' && str[length - 1] == '1')
		return (1);
	return (0);
}

static int	is_valid_first_last_line(char *str, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (str[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_rectangle(struct s_map map)
{
	int		i;
	char	**map1;

	i = 0;
	map1 = map.map;
	while (map1[i])
	{
		if ((i == 0 || map1[i][map.length] != '\n')
			&& !is_valid_first_last_line(map1[i], map.length))
			return (free(map1), 0);
		if (!check_first_and_last_1(map1[i], map.length))
			return (free(map1), 0);
		i++;
	}
	return (1);
}
