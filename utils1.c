/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:41:33 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/04 11:46:18 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_extention(char *file_name)
{
	int	length;

	length = ft_strlen(file_name);
	if (length >= 5 && file_name[length - 1] == 'r'
		&& file_name[length - 2] == 'e' && file_name[length - 3] == 'b'
		&& file_name[length - 4] == '.')
		return (1);
	else
		return (0);
}

void	reopen(int fd, char *name)
{
	close(fd);
	fd = open(name, O_RDONLY);
}

char	**copy_map(struct s_map map)
{
	char	**map1;
	int		i;
	int		j;

	i = 0;
	map1 = malloc((map.heigth + 1) * sizeof(map1));
	if (!map1)
		return (0);
	while (map.map[i])
	{
		j = 0;
		map1[i] = malloc((map.length + 1) * sizeof(char *));
		if (!map1[i])
			return (0);
		while (map.map[i][j])
		{
			map1[i][j] = map.map[i][j];
			j++;
		}
		map1[i][j] = '\0';
		i++;
	}
	map1[i] = 0;
	return (map1);
}

void	display_map(struct s_map map)
{
	int		i;

	i = 0;
	ft_printf("=======MAP=======\n");
	while (map.map[i])
	{
		ft_printf("%s", map.map[i]);
		i++;
	}
	ft_printf("\n=================\n");
	ft_printf("Map Heigth : %d\n", map.heigth);
	ft_printf("Map Length : %d\n", map.length);
	ft_printf("=================\n");
}

int	parse_map(int fd, char *name)
{
	struct s_map	map;

	if (!fd)
		return (0);
	map.map = get_map(fd, name, &map.length, &map.heigth);
	if (!map.map)
		return (0);
	map.collect_number = check_collectibles(map);
	ft_printf("number of collectibles : %d\n", map.collect_number);
	if (!check_rectangle(map) || !map.collect_number
		|| check_exit(map) != 1 || check_player(map) != 1)
		return (0);
	if (!find_path(map, map.collect_number))
		return (0);
	display_map(map);
	return (1);
}
