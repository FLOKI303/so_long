/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:17:22 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/09 17:21:45 by aait-mal         ###   ########.fr       */
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

int	myclose(t_map *map)
{
	map = NULL;
	exit(0);
	return (0);
}

int	hook_key(int keycode, t_map *map)
{
	if (keycode == 53)
		myclose(map);
	if (keycode == 13)
		update_map_up(*map, &(*map).player,
			&(*map).exit, &(*map).collect_number);
	if (keycode == 1)
		update_map_down(*map, &(*map).player,
			&(*map).exit, &(*map).collect_number);
	if (keycode == 0)
		update_map_left(*map, &(*map).player,
			&(*map).exit, &(*map).collect_number);
	if (keycode == 2)
		update_map_rigth(*map, &(*map).player,
			&(*map).exit, &(*map).collect_number);
	ft_printf(">> key : %d\n", keycode);
	mlx_clear_window((*map).mlx, (*map).mlx_win);
	print_elements((*map), (*map).mlx, (*map).mlx_win);
	return (0);
}

void	print_map(int fd, char *name)
{
	int		size_of_block;
	t_map	map;

	reopen(fd, name);
	map.map = get_map(fd, name, &map.length, &map.heigth);
	check_collectibles(map, &map.collect_number);
	display_map(map);
	size_of_block = 60;
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, map.length * size_of_block,
			map.heigth * size_of_block, "So Long");
	put_elements_ws(map, &map.wall, &map.space, map.mlx);
	put_elements_pe(map, &map.player, &map.exit, map.mlx);
	put_elements_co(map, &map.collectible, map.mlx);
	print_elements(map, map.mlx, map.mlx_win);
	mlx_hook(map.mlx_win, 2, 0, &hook_key, &map);
	mlx_hook(map.mlx_win, 17, 0, &myclose, &map);
	mlx_loop(map.mlx);
}
