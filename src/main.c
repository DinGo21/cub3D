/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:04:09 by disantam          #+#    #+#             */
/*   Updated: 2024/06/14 10:54:38 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_data(t_mlx *data)
{
	data->mlx = NULL;
	data->img = NULL;
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

static void	start_game(t_mlx *data, char *filename)
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
	start_game(&data, argv[1]);
	return (EXIT_SUCCESS);
}
