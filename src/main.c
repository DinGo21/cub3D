/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:04:09 by disantam          #+#    #+#             */
/*   Updated: 2024/06/26 11:44:35 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
/*
void	loop(void *param)
{
	t_mlx *data;

	data = param;
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	hooks(&data->player, &data->map, 0, 0);
	//cast_rays(mlx);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
*/
void	start_game(t_mlx *data)
{
	data->mlx = mlx_init(S_WIDTH, S_HEIGHT, "cuBit3D", true);
	if (!data->mlx)
	{
		parsing_error(&data->map, strerror(errno));
	}
	init_player(&data->player, &data->map);
	mlx_error(data, NULL);
	// if (load_textures(data, &data->map) == -1)
	// {
	// 	mlx_error(data, "Problems while loading textures");
	// }
	// mlx_key_hook(data->mlx, &key_hooks, &data);
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
