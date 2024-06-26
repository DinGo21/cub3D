/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:25:19 by disantam          #+#    #+#             */
/*   Updated: 2024/06/24 12:18:36 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	load_textures(t_mlx *data, t_map *map)
{
	print_matrix(map->txtr);
	data->textures[0] = mlx_load_png(map->txtr[0]);
	if (!data->textures[0])
		return (-1);
	data->textures[1] = mlx_load_png(map->txtr[1]);
	if (!data->textures[1])
		return (-1);
	data->textures[2] = mlx_load_png(map->txtr[2]);
	if (!data->textures[2])
		return (-1);
	data->textures[3] = mlx_load_png(map->txtr[3]);
	if (!data->textures[3])
		return (-1);
	return (0);
}

void	init_player(t_player *player, t_map *map)
{
	player->x = (map->plyr_x * TILE_SIZE) + TILE_SIZE / 2;
	player->y = (map->plyr_y * TILE_SIZE) + TILE_SIZE / 2;
	player->fov = FOV * M_PI / 180;
	if (map->map2d[map->plyr_y][map->plyr_x] == 'N')
		player->angle = 3 * M_PI / 2;
	if (map->map2d[map->plyr_y][map->plyr_x] == 'S')
		player->angle = M_PI / 2;
	if (map->map2d[map->plyr_y][map->plyr_x] == 'E')
		player->angle = 0;
	if (map->map2d[map->plyr_y][map->plyr_x] == 'W')
		player->angle = M_PI;
	player->rot = 0;
	player->l_r = 0;
	player->u_d = 0;
}

void	init_data(t_mlx *data)
{
	data->mlx = NULL;
	data->img = NULL;
	data->textures[NO] = NULL;
	data->textures[SO] = NULL;
	data->textures[WE] = NULL;
	data->textures[EA] = NULL;
	data->map.w_map = 0;
	data->map.h_map = 0;
	data->map.plyr_x = 0;
	data->map.plyr_y = 0;
	data->map.count = 0;
	data->map.map2d = NULL;
	data->map.cc = NULL;
	data->map.ff = NULL;
	data->map.txtr[NO] = NULL;
	data->map.txtr[SO] = NULL;
	data->map.txtr[WE] = NULL;
	data->map.txtr[EA] = NULL;
}
