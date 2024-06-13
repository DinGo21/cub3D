/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:39:56 by disantam          #+#    #+#             */
/*   Updated: 2024/06/13 14:19:37 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		printf("%s\n", matrix[i++]);
	}
}

int	is_element(char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
	{
		return (1);
	}
	if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
	{
		return (2);
	}
	return (0);
}

int	isplayer(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		return (1);
	}
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	c1;
	size_t	c2;
	char	*str;

	c1 = ft_strlen(s1);
	c2 = ft_strlen(s2);
	str = malloc(c1 + c2 + 1);
	if (!str)
	{
		return (NULL);
	}
	i = -1;
	while (++i < c1)
	{
		str[i] = s1[i];
	}
	i = -1;
	while (c1 + ++i < c1 + c2)
	{
		str[c1 + i] = s2[i];
	}
	str[c1 + c2] = '\0';
	return (free(s1), str);
}
