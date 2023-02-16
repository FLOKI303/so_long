/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:29:24 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/16 18:18:28 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (ft_putstr_fd("Error", 2), 1);
	else
	{
		if (!is_valid_extention(av[1]))
			return (ft_putstr_fd("Bad extention !", 2), 1);
		else
		{
			fd = open(av[1], O_RDONLY);
			if (fd == -1)
				return (ft_putstr_fd("File does not exist", 2), 1);
			else
			{
				if (!parse_map(fd, av[1]))
					return (ft_putstr_fd("Map Error !", 2), 1);
				else
					return (ft_putstr_fd("Good map", 1), 1);
			}
		}
	}
}
