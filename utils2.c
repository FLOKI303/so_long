/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:17:22 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/04 12:28:47 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(int fd, char *name)
{
	void			*mlx;
	void			*mlx_win;
	int				size_of_block;
	struct s_map	map;

	reopen(fd, name);
	map.map = get_map(fd, name, &map.length, &map.heigth);
	display_map(map);
	size_of_block = 60;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map.length * size_of_block,
			map.heigth * size_of_block, "So Long");
	mlx_loop(mlx);
}
