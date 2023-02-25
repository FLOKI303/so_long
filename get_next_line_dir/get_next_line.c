/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:34:30 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/23 18:07:49 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

static char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&s[i]);
	return (0);
}

static char	*get_whole_string(int fd, char *string)
{
	char	*buff;
	int		bytes_read;

	bytes_read = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(string, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(string);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		string = ft_strjoin(string, buff);
	}
	free(buff);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!string)
	{
		string = malloc(1 * sizeof(char));
		string[0] = '\0';
	}
	string = get_whole_string(fd, string);
	if (!string)
		return (NULL);
	line = get_new_line(string);
	string = get_left_string(string);
	return (line);
}
