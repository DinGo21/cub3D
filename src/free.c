/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:09:58 by disantam          #+#    #+#             */
/*   Updated: 2024/06/18 17:00:32 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_matrix(char **matrix)
{
	int	i;
	
	if (matrix != NULL)
	{
		i = 0;
		while (matrix[i] != NULL)
		{
			free(matrix[i++]);
		}
		free(matrix);
	}
}

void	free_mlx(t_mlx *data)
{
	int	i;

	i = 0;
	if (data->img != NULL)
	{
		mlx_delete_image(data->mlx, data->img);
	}
	mlx_close_window(data->mlx);
	while (i < 4)
	{
		if (data->textures[i] != NULL)
		{
			mlx_delete_texture(data->textures[i]);
		}
		i++;
	}
	if (data->mlx != NULL)
	{
		mlx_terminate(data->mlx);
	}
}

void	free_map(t_map *map)
{
	free_matrix(map->map2d);
	free_matrix(map->ff);
	free_matrix(map->cc);
	if (map->txtr[0] != NULL)
	{
		free(map->txtr[0]);
	}
	if (map->txtr[1] != NULL)
	{
		free(map->txtr[1]);
	}
	if (map->txtr[2] != NULL)
	{
		free(map->txtr[2]);
	}
	if (map->txtr[3] != NULL)
	{
		free(map->txtr[3]);
	}
}
