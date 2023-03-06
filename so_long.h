/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:02:01 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/06 16:29:33 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<unistd.h>
# include<stdlib.h>
# include<mlx.h>
# include<fcntl.h>
# include"get_next_line_dir/get_next_line.h"
# include"ft_printf_dir/ft_printf.h"

typedef struct s_map {
	char	**map;
	int		heigth;
	int		length;
	int		collect_number;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*space;
}				t_map;

char	*ft_strdup(const char *src);
int		is_valid_extention(char *file_name);
void	reopen(int fd, char *name);
void	display_map(t_map map);
int		parse_map(int fd, char *name);
char	**get_map(int fd, char *name, int *length, int *heigth);
int		check_rectangle(t_map map);
int		check_collectibles(t_map map);
int		check_player_exit(t_map map, char c);
int		check_exit(t_map map);
int		check_player(t_map map);
int		*get_pos(t_map map, char c, char **map1);
char	**copy_map(t_map map);
int		*get_pos(t_map map, char c, char **map1);
int		find_path(t_map map, int collect_number);
void	print_map(int fd, char *name);

#endif
