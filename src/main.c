/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:04:09 by disantam          #+#    #+#             */
/*   Updated: 2024/06/11 11:46:42 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_map(t_map *map)
{
	map->w_map = 0;
	map->h_map = 0;
	map->plyr_x = 0;
	map->plyr_y = 0;
	map->count = 0;
	map->map = NULL;
	map->cc = NULL;
	map->ff = NULL;
	map->txtr[0] = NULL;
	map->txtr[1] = NULL;
	map->txtr[2] = NULL;
	map->txtr[3] = NULL;
}

void	init_data(t_mlx *data, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error(strerror(errno));
		exit(EXIT_FAILURE);
	}
	init_map(&data->map);
	parse_elements(&data->map, fd);
	parse_map(&data->map, fd);
	close(fd);
	parsing_error(&data->map, NULL);
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
	init_data(&data, argv[1]);
	return (EXIT_SUCCESS);
}
