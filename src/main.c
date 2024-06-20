/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:04:09 by disantam          #+#    #+#             */
/*   Updated: 2024/06/20 11:29:21 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	//parsing_error(&data->map, NULL);
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
