/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:35:46 by aait-mal          #+#    #+#             */
/*   Updated: 2023/02/23 17:56:58 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	i;
	size_t	len;

	i = 0;
	copy = malloc((ft_strlen((char *)src) + 1) * sizeof(char));
	if (!copy)
		return (0);
	len = ft_strlen((char *)src);
	while (i < len)
	{
		copy[i] = (char)src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
