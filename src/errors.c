/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:25:01 by disantam          #+#    #+#             */
/*   Updated: 2024/06/13 16:02:26 by disantam         ###   ########.fr       */
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

void	ft_error(char *err_message)
{
	int	nb;

	nb = 0;
	if (err_message != NULL)
	{
		nb = write(2, "Error\n", 6);
		nb = write(2, err_message, ft_strlen(err_message));
		nb = write(2, "\n", 1);
	}
	(void)nb;
}


void	parsing_error(t_map *map, char *err_message)
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
	ft_error(err_message);
	exit(EXIT_FAILURE);
}
