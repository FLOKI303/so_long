/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:45:31 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/07 12:04:06 by aait-mal         ###   ########.fr       */
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

int	check_rectangle(t_map map)
{
	int		i;

	i = 0;
	while (map.map[i])
	{
		if ((i == 0 || map.map[i][map.length] != '\n')
			&& !is_valid_first_last_line(map.map[i], map.length))
			return (0);
		if (!check_first_and_last_1(map.map[i], map.length))
			return (0);
		i++;
	}
	return (1);
}
