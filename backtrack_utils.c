/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:40:45 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/08 10:45:14 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	store_previous_collects(int	**all_collect, int *collect_pos, int i)
{
	all_collect[i] = malloc(2 * sizeof(int));
	all_collect[i][0] = collect_pos[0];
	all_collect[i][1] = collect_pos[1];
}

void	free_three(char **map1, int **all_collect, int *collect_pos, int i)
{
	free_all(map1);
	free_int(all_collect, i);
	free(collect_pos);
}
