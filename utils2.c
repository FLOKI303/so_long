/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:17:22 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/08 11:16:59 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_elements(t_map map, void *mlx, void *mlx_win)
{
	int	x;
	int	y;
	int	s;

	s = 60;
	y = 0;
	while (map.map[y])
	{
		x = -1;
		while (map.map[y][++x])
		{
			if (map.map[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, map.wall, x * s, y * s);
			if (map.map[y][x] == '0')
				mlx_put_image_to_window(mlx, mlx_win, map.space, x * s, y * s);
			if (map.map[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win,
					map.collectible, x * s, y * s);
			if (map.map[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, map.player, x * s, y * s);
			if (map.map[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, map.exit, x * s, y * s);
		}
		y++;
	}
}

void	print_map(int fd, char *name)
{
	void	*mlx;
	void	*mlx_win;
	int		size_of_block;
	t_map	map;

	reopen(fd, name);
	map.map = get_map(fd, name, &map.length, &map.heigth);
	display_map(map);
	size_of_block = 60;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map.length * size_of_block,
			map.heigth * size_of_block, "So Long");
	put_elements_ws(map, &map.wall, &map.space, mlx);
	put_elements_pe(map, &map.player, &map.exit, mlx);
	put_elements_co(map, &map.collectible, mlx);
	print_elements(map, mlx, mlx_win);
	mlx_loop(mlx);
}
