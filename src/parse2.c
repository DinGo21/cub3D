/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:57:01 by disantam          #+#    #+#             */
/*   Updated: 2024/06/13 15:22:44 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_map(t_map *map)
{
	int y;
	int	x;
	char *newline;

	y = 0;
	x = 0;
	while (map->map2d[y] != NULL)
	{
		x = ft_strlen(map->map2d[y]);
		if (x < map->w_map)
		{
			newline = ft_calloc(sizeof(char), map->w_map + 1);
			if (!newline)
				parsing_error(map, strerror(errno));
			ft_strlcpy(newline, map->map2d[y], x + 1);
			ft_memset(newline + x, ' ', map->w_map - x);
			free(map->map2d[y]);
			map->map2d[y] = newline;
		}
		y++;
	}
}

static void	get_mapsize(char **map2d, int *height, int *width)
{
	int	y;
	int	x;

	y = 0;
	while(map2d[y] != NULL)
	{
		x = 0;
		while (map2d[y][x] != '\0')
		{
			x++;
		}
		if (x > *width)
			*width = x;
		y++;
	}
	*height = y;
}

static char	*skip_empty_lines(t_map *map, char *line, int fd)
{
	int	i;

	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] != '\n' && line[i] != '\0')
			return (line);
		if (line[i] == '\0')
		{
			free(line);
			parsing_error(map, "unexpected EOF");
		}
		free(line);
		line = get_next_line(fd);
	}
	return (NULL);
}

void	parse_map(t_map *map, char *line, int fd)
{
	char *tmp;

	line = skip_empty_lines(map, line, fd);
	tmp = ft_strdup("");
	while (line)
	{
		tmp = ft_join(tmp, line);
		free(line);
		if (!tmp)
			parsing_error(map, strerror(errno));
		line = get_next_line(fd);
	}
	map->map2d = ft_split(tmp, '\n');
	free(tmp);
	if (!map->map2d)
		parsing_error(map, strerror(errno));
	get_mapsize(map->map2d, &map->h_map, &map->w_map);
	fill_map(map);
	print_matrix(map->map2d);
	check_map(map);
}
