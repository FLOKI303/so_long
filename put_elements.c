/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:08:59 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/08 15:51:34 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_elements_ws(t_map map, void **wall, void **space, void *mlx)
{
	*wall = mlx_xpm_file_to_image(mlx,
			"./xpm/walls/wall1.xpm", &map.length, &map.heigth);
	*space = mlx_xpm_file_to_image(mlx,
			"./xpm/grounds/ground1.xpm", &map.length, &map.heigth);
}

void	put_elements_pe(t_map map, void **player, void **exit, void *mlx)
{
	*player = mlx_xpm_file_to_image(mlx,
			"./xpm/player/skeleton_down1.xpm", &map.length, &map.heigth);
	*exit = mlx_xpm_file_to_image(mlx,
			"./xpm/exit/exit1_1.xpm", &map.length, &map.heigth);
}

void	put_elements_co(t_map map, void **collectible, void *mlx)
{
	*collectible = mlx_xpm_file_to_image(mlx,
			"./xpm/collectibles/bone1.xpm", &map.length, &map.heigth);
}
