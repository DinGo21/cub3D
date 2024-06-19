/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:40:45 by disantam          #+#    #+#             */
/*   Updated: 2024/06/19 15:39:26 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	key_release(mlx_key_data_t *keydata, t_mlx *data)
{
	if (keydata->key == MLX_KEY_A && keydata->action == MLX_RELEASE)
		data->player.l_r = 0;
	if (keydata->key == MLX_KEY_D && keydata->action == MLX_RELEASE)
		data->player.l_r = 0;
	if (keydata->key == MLX_KEY_W && keydata->action == MLX_RELEASE)
		data->player.u_d = 0;
	if (keydata->key == MLX_KEY_S && keydata->action == MLX_RELEASE)
		data->player.u_d = 0;
	if (keydata->key == MLX_KEY_LEFT && keydata->action == MLX_RELEASE)
		data->player.rot = 0;
	if (keydata->key == MLX_KEY_RIGHT && keydata->action == MLX_RELEASE)
		data->player.rot = 0;
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_mlx *data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS
		|| keydata.action == MLX_REPEAT))
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		data->player.l_r = -1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		data->player.l_r = 1;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		data->player.u_d = -1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		data->player.u_d = 1;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		data->player.rot = -1;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		data->player.rot = 1;
	key_release(&keydata, data);
}

void	rotate_player(t_player *player, int f)
{
	if (f == 1)
	{
		player->angle += ROTATION_SPEED;
		if (player->angle > 2 * M_PI)
			player->angle -= 2 * M_PI;
	}
	if (f == 0)
	{
		player->angle -= ROTATION_SPEED;
		if (player->angle < 0)
			player->angle += 2 * M_PI;
	}
}

void	move_player(t_player *player, t_map *map, double y, double x)
{
	int grid_y;
	int	grid_x;
	int	new_y;
	int	new_x;

	new_y = roundf(player->y + y);
	new_x = roundf(player->x + x);
	grid_y = (new_y / TILE_SIZE);
	grid_x = (new_x / TILE_SIZE);
	if (map->map2d[grid_y][grid_x] != '1' &&
		map->map2d[grid_y][player->x / TILE_SIZE] != '1' &&
		map->map2d[player->y / TILE_SIZE][grid_y] != '1')
	{
		player->y = new_y;
		player->x = new_x;
	}
}

void	hooks(t_player *player, double y, double x)
{
	if (player->rot == 1)
		rotate_player(player, 1);
	if (player->rot == -1)
		rotate_player(player, 0);
	if (player->l_r == 1)
	{
		y = cos(player->angle) * PLAYER_SPEED;
		x = -sin(player->angle) * PLAYER_SPEED;
	}
	if (player->l_r == -1)
	{
		y = -cos(player->angle) * PLAYER_SPEED;
		x = sin(player->angle) * PLAYER_SPEED;
	}
	if (player->u_d == 1)
	{
		y = cos(player->angle) * PLAYER_SPEED;
		x = sin(player->angle) * PLAYER_SPEED;
	}
	if (player->u_d == -1)
	{
		y = -cos(player->angle) * PLAYER_SPEED;
		x = -sin(player->angle) * PLAYER_SPEED;
	}
}
