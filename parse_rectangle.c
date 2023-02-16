/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:45:31 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/16 18:13:29 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_first_and_last_1(char *str, int length)
{
	int	valid;

	valid = 0;
	if (str[0] == '1')
	{
		if (str[length - 1] == '\n' && str[length - 2] == '1')
			valid = 1;
		else if (str[length - 1] == '1')
			valid = 1;
	}
	return (valid);
}

static int	is_valid_first_last_line(char *str, int length)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || (str[i] == '\n' && i == length - 1))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	help_check(char *line, int length, int prev_length, int *i)
{
	if (prev_length != length || !check_first_and_last_1(line, length)
		|| (((*i)++ == 0 || line[length - 1] != '\n')
			&& !is_valid_first_last_line(line, length)))
		return (0);
	return (1);
}

int	check_rectangle(int fd)
{
	char	*line;
	char	*prev_line;
	int		length;
	int		prev_length;
	int		i;

	line = get_next_line(fd);
	length = ft_strlen(line);
	prev_length = length;
	if (!line)
		return (0);
	i = 0;
	while (line)
	{
		if (!help_check(line, length, prev_length, &i))
			return (free(line), free(prev_line), 0);
		prev_line = ft_strdup(line);
		line = get_next_line(fd);
		length = ft_strlen(line);
		if (line && line[length - 1] != '\n')
			prev_length--;
	}
	if (prev_line[prev_length - 1] == '\n')
		return (free(line), free(prev_line), 0);
	return (free(line), free(prev_line), 1);
}
