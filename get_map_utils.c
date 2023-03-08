/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:01:37 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/08 11:01:58 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_first_time(unsigned int *length,
		int *map_length, int *check, char *line)
{
	*length = ft_strlen(line);
	*map_length = *length - 1;
	*check = 0;
}
