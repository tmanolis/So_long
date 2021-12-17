/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:51:31 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/17 13:36:32 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images(t_data *data)
{
	data->img.wall_down = mlx_xpm_file_to_image(data->mlx, \
	"assets/wall_down.xpm", &data->img.width, &data->img.height);
	data->img.wall_top = mlx_xpm_file_to_image(data->mlx, \
	"assets/wall_top.xpm", &data->img.width, &data->img.height);
	data->img.wall_left = mlx_xpm_file_to_image(data->mlx, \
	"assets/wall_left.xpm", &data->img.width, &data->img.height);
	data->img.wall_right = mlx_xpm_file_to_image(data->mlx, \
	"assets/wall_right.xpm", &data->img.width, &data->img.height);
	data->img.wall_l_d_c = mlx_xpm_file_to_image(data->mlx, \
	"assets/l_d_corner.xpm", &data->img.width, &data->img.height);
	data->img.wall_l_t_c = mlx_xpm_file_to_image(data->mlx, \
	"assets/l_t_c.xpm", &data->img.width, &data->img.height);
	data->img.wall_r_t_c = mlx_xpm_file_to_image(data->mlx, \
	"assets/r_t_c.xpm", &data->img.width, &data->img.height);
	data->img.wall_r_d_c = mlx_xpm_file_to_image(data->mlx, \
	"assets/r_d_c.xpm", &data->img.width, &data->img.height);
	data->img.ground = mlx_xpm_file_to_image(data->mlx, \
	"assets/ground.xpm", &data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, \
	"assets/player.xpm", &data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, \
	"assets/exit.xpm", &data->img.width, &data->img.height);
	data->img.collectible = mlx_xpm_file_to_image(data->mlx, \
	"assets/collectible.xpm", &data->img.width, &data->img.height);
}
