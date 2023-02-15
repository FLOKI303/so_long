/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:02:01 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/15 18:16:53 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<unistd.h>
# include<stdlib.h>
# include<mlx.h>
# include<fcntl.h>
# include<stdio.h>
# include"get_next_line_dir/get_next_line.h"

void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *src);
int		is_valid_extention(char *file_name);
int		parse_map(int fd, char *name);
int		check_rectangle(int fd);
int		check_collectibles(int fd);

#endif
