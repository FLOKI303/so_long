/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:59:33 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/09 17:21:18 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_map_up(t_map map, void **player,
			void **exit_pos, int *collect_number)
{
	int	*player_pos;

	player_pos = get_pos(map, 'P', map.map);
	if (map.map[player_pos[0] - 1][player_pos[1]] != '1')
	{
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/skeleton_up1.xpm", &map.length, &map.heigth);
		if (*collect_number == 1
			&& (map.map[player_pos[0] - 1][player_pos[1]] == 'C'))
			*exit_pos = mlx_xpm_file_to_image(map.mlx,
					"./xpm/exit/exit4_1.xpm", &map.length, &map.heigth);
		if (map.map[player_pos[0] - 1][player_pos[1]] == 'C')
			(*collect_number)--;
		else if (map.map[player_pos[0] - 1][player_pos[1]] == 'E'
				&& *collect_number != 0)
			return ;
		else if (map.map[player_pos[0] - 1][player_pos[1]] == 'E'
				&& *collect_number == 0)
			exit(0);
		map.map[player_pos[0] - 1][player_pos[1]] = 'P';
		map.map[player_pos[0]][player_pos[1]] = '0';
		ft_printf("|collect_number : %d|\n", *collect_number);
	}
}

void	update_map_down(t_map map, void **player,
			void **exit_pos, int *collect_number)
{
	int	*player_pos;

	player_pos = get_pos(map, 'P', map.map);
	if (map.map[player_pos[0] + 1][player_pos[1]] != '1')
	{
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/skeleton_down1.xpm", &map.length, &map.heigth);
		if (*collect_number == 1
			&& (map.map[player_pos[0] + 1][player_pos[1]] == 'C'))
			*exit_pos = mlx_xpm_file_to_image(map.mlx,
					"./xpm/exit/exit4_1.xpm", &map.length, &map.heigth);
		if (map.map[player_pos[0] + 1][player_pos[1]] == 'C')
			(*collect_number)--;
		else if (map.map[player_pos[0] + 1][player_pos[1]] == 'E'
				&& *collect_number != 0)
			return ;
		else if (map.map[player_pos[0] + 1][player_pos[1]] == 'E'
				&& *collect_number == 0)
			exit(0);
		map.map[player_pos[0] + 1][player_pos[1]] = 'P';
		map.map[player_pos[0]][player_pos[1]] = '0';
		ft_printf("|collect_number : %d|\n", *collect_number);
	}
}

void	update_map_left(t_map map, void **player,
			void **exit_pos, int *collect_number)
{
	int	*player_pos;

	player_pos = get_pos(map, 'P', map.map);
	if (map.map[player_pos[0]][player_pos[1] - 1] != '1')
	{
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/skeleton_left1.xpm", &map.length, &map.heigth);
		if (*collect_number == 1
			&& (map.map[player_pos[0]][player_pos[1] - 1] == 'C'))
			*exit_pos = mlx_xpm_file_to_image(map.mlx,
					"./xpm/exit/exit4_1.xpm", &map.length, &map.heigth);
		if (map.map[player_pos[0]][player_pos[1] - 1] == 'C')
			(*collect_number)--;
		else if (map.map[player_pos[0]][player_pos[1] - 1] == 'E'
				&& *collect_number != 0)
			return ;
		else if (map.map[player_pos[0]][player_pos[1] - 1] == 'E'
				&& *collect_number == 0)
			exit(0);
		map.map[player_pos[0]][player_pos[1] - 1] = 'P';
		map.map[player_pos[0]][player_pos[1]] = '0';
		ft_printf("|collect_number : %d|\n", *collect_number);
	}
}

void	update_map_rigth(t_map map, void **player,
			void **exit_pos, int *collect_number)
{
	int	*player_pos;

	player_pos = get_pos(map, 'P', map.map);
	if (map.map[player_pos[0]][player_pos[1] + 1] != '1')
	{
		*player = mlx_xpm_file_to_image(map.mlx,
				"./xpm/player/skeleton_rigth1.xpm", &map.length, &map.heigth);
		if (*collect_number == 1
			&& (map.map[player_pos[0]][player_pos[1] + 1] == 'C'))
			*exit_pos = mlx_xpm_file_to_image(map.mlx,
					"./xpm/exit/exit4_1.xpm", &map.length, &map.heigth);
		if (map.map[player_pos[0]][player_pos[1] + 1] == 'C')
			(*collect_number)--;
		else if (map.map[player_pos[0]][player_pos[1] + 1] == 'E'
				&& *collect_number != 0)
			return ;
		else if (map.map[player_pos[0]][player_pos[1] + 1] == 'E'
				&& *collect_number == 0)
			exit(0);
		map.map[player_pos[0]][player_pos[1] + 1] = 'P';
		map.map[player_pos[0]][player_pos[1]] = '0';
		ft_printf("|collect_number : %d|\n", *collect_number);
	}
}
