/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:04:09 by disantam          #+#    #+#             */
/*   Updated: 2024/06/18 17:13:05 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void init_player(t_player *player, t_map *map)
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

int	load_textures(t_mlx *data, t_map *map)
{
	print_matrix(map->txtr);
	data->textures[NO] = mlx_load_png(map->txtr[NO]);
	if (!data->textures[NO])
		return (-1);
	data->textures[SO] = mlx_load_png(map->txtr[SO]);
	if (!data->textures[SO])
		return (-1);
	data->textures[WE] = mlx_load_png(map->txtr[WE]);
	if (!data->textures[WE])
		return (-1);
	data->textures[EA] = mlx_load_png(map->txtr[EA]);
	if (!data->textures[EA])
		return (-1);
	return (0);
}

static void	init_data(t_mlx *data)
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
	data->map.txtr[0] = NULL;
	data->map.txtr[1] = NULL;
	data->map.txtr[2] = NULL;
	data->map.txtr[3] = NULL;
}

static void	get_args(t_mlx *data, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error(strerror(errno));
		exit(EXIT_FAILURE);
	}
	init_data(data);
	parse_elements(&data->map, fd);
	close(fd);
	parsing_error(&data->map, NULL);
}

void	start_game(t_mlx *data)
{
	data->mlx = mlx_init(S_WIDTH, S_HEIGHT, "cuBit3D", true);
	if (!data->mlx)
	{
		parsing_error(&data->map, strerror(errno));
	}
	if (load_textures(data, &data->map) == -1)
	{
		mlx_error(data, "Problems while loading textures");
	}
	init_player(&data->player, &data->map);
	//mlx_key_hook(data->mlx, &key_hooks, &data);
	//mlx_loop_hook(data->mlx, &loop, &data);
	//mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
	t_mlx	data;

	if (argc < 2)
	{
		ft_error("Not enough arguments");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 4) != 0)
	{
		ft_error("Filetype is not .cub");
		exit(EXIT_FAILURE);
	}
	get_args(&data, argv[1]);
	start_game(&data);
	return (EXIT_SUCCESS);
}
