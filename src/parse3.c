/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:21:38 by disantam          #+#    #+#             */
/*   Updated: 2024/06/13 14:19:39 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void check_position(t_map *map, char **map2d, int y, int x)
{
	if (isplayer(map2d[y][x]) && map->plyr_x != 0)
	{
		parsing_error(map, "multiple players");
	}
	if (isplayer(map2d[y][x]) && map->plyr_x == 0)
	{
		map->plyr_x = x;
		map->plyr_y = y;
	}
	if (map2d[y][x] == '0' || isplayer(map2d[y][x]))
	{
		if (map2d[y][x + 1] == ' ' || map2d[y][x - 1] == ' '
			|| map2d[y + 1][x] == ' ' || map2d[y - 1][x] == ' ')
		{
			parsing_error(map, "invalid map");
		}
	}
}

static void	check_line(t_map *map, char **map2d, int y)
{
	int	x;

	x = 1;
	if (!ft_strchr(" 1", map2d[y][0]))
	{
		parsing_error(map, "invalid map");
	}
	while (map2d[y][x + 1] != '\0')
	{
		if (!ft_strchr(" 01NSEW", map2d[y][x]))
		{
			parsing_error(map, "invalid character");
		}
		check_position(map, map2d, y, x);
		x++;
	}
	if (!ft_strchr(" 1", map2d[y][x]))
	{
		parsing_error(map, "invalid map");
	}
}

void	check_map(t_map *map)
{
	int	y;
	int	x;
	
	x = 0;
	while (map->map2d[0][x] == ' ' || map->map2d[0][x] == '1')
		x++;
	if (map->map2d[0][x] != '\0')
	{
		parsing_error(map, "invalid map");
	}
	y = 0;
	while (map->map2d[++y + 1] != NULL)
	{
		check_line(map, map->map2d, y);
	}
	x = 0;
	while (map->map2d[y][x] == ' ' || map->map2d[y][x] == '1')
		x++;
	if (map->map2d[y][x] != '\0')
	{
		parsing_error(map, "invalid map");
	}
}
