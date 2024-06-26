/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:16:04 by disantam          #+#    #+#             */
/*   Updated: 2024/06/20 12:16:06 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define M_PI 3.14159265358979323846
# define S_WIDTH 1900 // Screen width
# define S_HEIGHT 1000 // Screen height
# define TILE_SIZE 30 // Tile size
# define FOV 60 // Field of View
# define ROTATION_SPEED 0.045 // Rotation speed
# define PLAYER_SPEED 4 // Player speed

# define NO 0 // North orientation
# define SO 1 // South orientation
# define WE 2 // West orientation
# define EA 3 // East orientation

/**
 * The player structure.
 * 
 * @param x Player x position.
 * @param y Player y position.
 * @param angle Player angle.
 * @param fov Field of View in radians.
 * @param rot Rotation flag.
 * @param l_r Left and right flag.
 * @param u_d Up and down flag.
*/
typedef struct s_player
{
	int		x;
	int		y;
	double	angle;
	float	fov;
	int		rot;
	int		l_r;
	int		u_d;
}	t_player;

/**
 * The ray structure.
 * 
 * @param ray_ngl Ray angle
 * @param distance Distance to the wall
 * @param flag Flag for the wall
*/
typedef struct s_ray
{
	double	ray_ngl;
	double	distance;
	int		flag;
}	t_ray;

/**
 * Structure containing information of the 2D map.
 * 
 * @param map Matrix of the 2D map.
 * @param w_map Map width.
 * @param h_map Map height.
 * @param plyr_x Player x position in the map.
 * @param plyr_y Player y position in the map.
 * @param ff RGB colors for the floor.
 * @param cc RGB colors for the ceiling.
 * @param txtr Paths of each texture.
 * @param count Counter of elements found during parsing
*/
typedef struct s_map
{
	char	**map2d;
	int		w_map;
	int		h_map;
	int		plyr_x;
	int		plyr_y;
	char	**ff;
	char	**cc;
	char	*txtr[4];
	int		count;
}	t_map;

/**
 * Structure contaning the mlx pointer and all structs.
 * 
 * @param mlx Mlx pointer.
 * @param img Image pointer.
 * @param tx_buffer Array containing pointers to the textures.
 * @param map Map structure.
 * @param player Player structure.
 * @param ray Ray structure.
*/
typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*textures[4];
	t_map			map;
	t_player		player;
	t_ray			ray;
}	t_mlx;

// init //

int		load_textures(t_mlx *data, t_map *map);
void	init_data(t_mlx *data);
void	init_player(t_player *player, t_map *map);

// parsing //

void	parse_elements(t_map *map, int fd);
void	parse_map(t_map *map, char *line, int fd);
void	check_map(t_map *map);

// hooks //

void	hooks(t_player *player, t_map *map, double y, double x);
void	key_hooks(mlx_key_data_t keydata, void *param);

// utils //

int		isplayer(char c);
int		is_element(char *line);
char	*ft_join(char *s1, char *s2);
void	print_matrix(char **matrix);

// errors //

void	ft_error(char *err_message);
void	parsing_error(t_map *map, char *err_message);
void	mlx_error(t_mlx *data, char *err_mesage);


// frees //

void	free_matrix(char **matrix);
void    free_map(t_map *map);
void	free_mlx(t_mlx *data);

#endif
