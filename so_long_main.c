/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:29:24 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/26 19:23:05 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (ft_printf("Error"), 1);
	else
	{
		if (!is_valid_extention(av[1]))
			return (ft_printf("Bad extention !"), 1);
		else
		{
			fd = open(av[1], O_RDONLY);
			if (fd == -1)
				return (ft_printf("File does not exist"), 1);
			else
			{
				if (!parse_map(fd, av[1]))
					return (ft_printf("Map Error !"), 1);
				else
				{
					return (ft_printf("Good map"), 1);
				}
			}
		}
	}
	return (0);
}
