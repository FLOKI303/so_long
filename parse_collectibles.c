/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_collectibles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:12:03 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/15 18:58:18 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectibles(int fd)
{
	char	*line;
	int		length;
	int		i;
	int		j;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		length = ft_strlen(line);
		if (line[length - 1] != '\n')
			break ;
		if (i++ != 0)
		{
			j = -1;
			while (line[++j])
			{
				if (j != 0 && j != length - 2)
					if (line[j] == 'C')
						return (free(line), 1);
			}
		}
	}
	return (free(line), 0);
}
