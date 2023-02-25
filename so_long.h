/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:02:01 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/24 13:28:47 by aait-mal         ###   ########.fr       */
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

struct	s_map {
	char	**map;
	int		heigth;
	int		length;
};

char	*ft_strdup(const char *src);
void	free_all(char **p, size_t j);
int		is_valid_extention(char *file_name);
void	reopen(int fd, char *name);
void	display_map(struct s_map map);
int		parse_map(int fd, char *name);
char	**get_map(int fd, char *name, int *length, int *heigth);
int		check_rectangle(struct s_map map);
int		check_collectibles(struct s_map map);
int		check_player_exit(struct s_map map, char c);
int		check_exit(struct s_map map);
int		check_player(struct s_map map);
int		find_path(struct s_map map);

#endif
