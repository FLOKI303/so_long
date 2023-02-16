/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:38:19 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/11 16:12:53 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putchar_fd(char c, int fd, int *length)
{
	write(fd, &c, 1);
	(*length)++;
}

void	ft_putstr_fd(char *s, int fd, int *length)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1, length);
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s, fd, length);
		s++;
	}
}
