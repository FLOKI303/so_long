/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:17:22 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/07 14:59:28 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_elements(t_map map, void **wall, void **space, void **player, void **exit, void **collectible, void *mlx)
{
	*wall = mlx_xpm_file_to_image(mlx, "./xpm/wall2.xpm", &map.length, &map.heigth);
	*space = mlx_xpm_file_to_image(mlx, "./xpm/ground1.xpm", &map.length, &map.heigth);
	*player = mlx_xpm_file_to_image(mlx, "./xpm/player/skeleton_down.xpm", &map.length, &map.heigth);
	*collectible = mlx_xpm_file_to_image(mlx, "./xpm/bone.xpm", &map.length, &map.heigth);
	(void)exit;
}

void	print_elements(t_map map, void *mlx, void *mlx_win)
{
	int	x;
	int	y;
	int	size;

	size = 50;
	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, map.wall, x * size, y * size);
			if (map.map[y][x] == '0')
				mlx_put_image_to_window(mlx, mlx_win, map.space, x * size, y * size);
			if (map.map[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx, mlx_win, map.space, x * size, y * size);
				mlx_put_image_to_window(mlx, mlx_win, map.collectible, x * size, y * size);
			}
			if (map.map[y][x] == 'P')
			{
				mlx_put_image_to_window(mlx, mlx_win, map.space, x * size, y * size);
				mlx_put_image_to_window(mlx, mlx_win, map.player, x * size, y * size);
			}
			x++;
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
	size_of_block = 50;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map.length * size_of_block,
			map.heigth * size_of_block, "So Long");
	put_elements(map, &map.wall, &map.space, &map.player, &map.exit, &map.collectible, mlx);
	print_elements(map, mlx, mlx_win);
	mlx_loop(mlx);
}
