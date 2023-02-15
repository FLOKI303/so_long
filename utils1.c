/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:41:33 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/15 12:49:36 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_extention(char *file_name)
{
	int	length;

	length = ft_strlen(file_name);
	if (length >= 5 && file_name[length - 1] == 'r'
		&& file_name[length - 2] == 'e' && file_name[length - 3] == 'b'
		&& file_name[length - 4] == '.')
		return (1);
	else
		return (0);
}

int	parse_map(int fd)
{
	if (!fd)
		return (0);
	if (!check_rectangle(fd))
		return (0);
	return (1);
}
