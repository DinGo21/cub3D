/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:25:01 by disantam          #+#    #+#             */
/*   Updated: 2024/06/17 16:06:01 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	free_map(map);
	ft_error(err_message);
	exit(EXIT_FAILURE);
}

void	mlx_error(t_mlx *data, char *err_message)
{
	free_mlx(data);
	free_map(&data->map);
	ft_error(err_message);
	exit(EXIT_FAILURE);
}
