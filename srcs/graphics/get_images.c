/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:51:31 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/14 16:20:13 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images(t_data *data)
{
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "assets/test.xpm", &data->img.width, &data->img.height);
	// data->img.ground = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm", &data->img.width, &data->img.height);

}