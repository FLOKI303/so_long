/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:02:01 by aait-mal          #+#    #+#             */
/*   Updated: 2023/03/09 18:14:21 by aait-mal         ###   ########.fr       */
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
	int		fix_collect_number;
	int		collect_number;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*space;
	void	*mlx;
	void	*mlx_win;
}				t_map;

char	*ft_strdup(const char *src);
int		is_valid_extention(char *file_name);
void	reopen(int fd, char *name);
void	display_map(t_map map);
int		parse_map(int fd, char *name);
char	**get_map(int fd, char *name, int *length, int *heigth);
void	check_first_time(unsigned int *length,
			int *map_length, int *check, char *line);
int		check_rectangle(t_map map);
int		check_collectibles(t_map map, int *collect_number);
int		check_player_exit(t_map map, char c);
int		check_exit(t_map map);
int		check_player(t_map map);
int		*get_pos(t_map map, char c, char **map1);
char	**copy_map(t_map map);
int		*get_pos(t_map map, char c, char **map1);
void	store_previous_collects(int	**all_collect, int *collect_pos, int i);
void	free_three(char **map1, int **all_collect, int *collect_pos, int i);
int		find_path(t_map map, int collect_number);
void	print_map(int fd, char *name);
void	free_all(char **p);
void	free_int(int **p, int sz);
void	put_elements_ws(t_map map, void **wall, void **space, void *mlx);
void	put_elements_pe(t_map map, void **player, void **exit, void *mlx);
void	put_elements_co(t_map map, void **collectible, void *mlx);
void	print_elements(t_map map, void *mlx, void *mlx_win);
void	update_map_up(t_map map, void **player,
			void **exit, int *collect_number);
void	update_map_down(t_map map, void **player,
			void **exit, int *collect_number);
void	update_map_left(t_map map, void **player,
			void **exit, int *collect_number);
void	update_map_rigth(t_map map, void **player,
			void **exit, int *collect_number);
void	check_collect_number_up(t_map map, void **player,
			void **exit_pos, int *player_pos);
void	check_collect_number_down(t_map map, void **player,
			void **exit_pos, int *player_pos);
void	check_collect_number_left(t_map map, void **player,
			void **exit_pos, int *player_pos);
void	check_collect_number_rigth(t_map map, void **player,
			void **exit_pos, int *player_pos);

#endif
