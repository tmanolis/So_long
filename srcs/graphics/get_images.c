/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:51:31 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/16 15:36:20 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images(t_data *data)
{
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm", &data->img.width, &data->img.height);
	data->img.wall_top = mlx_xpm_file_to_image(data->mlx, "assets/wall_top.xpm", &data->img.width, &data->img.height);
	data->img.ground = mlx_xpm_file_to_image(data->mlx, "assets/ground.xpm", &data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm", &data->img.width, &data->img.height);

}