/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:13:13 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/09 18:26:20 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collect_number_up(t_map map, void **player,
			void **exit_pos, int *player_pos)
{
	if (map.collect_number == 1
		&& (map.map[player_pos[0] - 1][player_pos[1]] == 'C'))
		*exit_pos = mlx_xpm_file_to_image(map.mlx,
				"./xpm/exit/exit4.xpm", &map.length, &map.heigth);
	if (map.collect_number == 0)
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/robe_up.xpm", &map.length, &map.heigth);
	else if (map.collect_number <= map.fix_collect_number / 2)
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/body_up.xpm", &map.length, &map.heigth);
}

void	check_collect_number_down(t_map map, void **player,
			void **exit_pos, int *player_pos)
{
	if (map.collect_number == 1
		&& (map.map[player_pos[0] + 1][player_pos[1]] == 'C'))
		*exit_pos = mlx_xpm_file_to_image(map.mlx,
				"./xpm/exit/exit4.xpm", &map.length, &map.heigth);
	if (map.collect_number == 0)
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/robe_down.xpm", &map.length, &map.heigth);
	else if (map.collect_number <= map.fix_collect_number / 2)
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/body_down.xpm", &map.length, &map.heigth);
}

void	check_collect_number_left(t_map map, void **player,
			void **exit_pos, int *player_pos)
{
	if (map.collect_number == 1
		&& (map.map[player_pos[0]][player_pos[1] - 1] == 'C'))
		*exit_pos = mlx_xpm_file_to_image(map.mlx,
				"./xpm/exit/exit4.xpm", &map.length, &map.heigth);
	if (map.collect_number == 0)
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/robe_left.xpm", &map.length, &map.heigth);
	else if (map.collect_number <= map.fix_collect_number / 2)
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/body_left.xpm", &map.length, &map.heigth);
}

void	check_collect_number_rigth(t_map map, void **player,
			void **exit_pos, int *player_pos)
{
	if (map.collect_number == 1
		&& (map.map[player_pos[0]][player_pos[1] + 1] == 'C'))
		*exit_pos = mlx_xpm_file_to_image(map.mlx,
				"./xpm/exit/exit4.xpm", &map.length, &map.heigth);
	if (map.collect_number == 0)
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/robe_rigth.xpm", &map.length, &map.heigth);
	else if (map.collect_number <= map.fix_collect_number / 2)
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/body_rigth.xpm", &map.length, &map.heigth);
}
