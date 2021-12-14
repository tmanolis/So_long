/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:09:56 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/14 16:20:36 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	render(t_data *data)
// {
// 	if (data->win == NULL)
// 		return (FAILURE);
// 	mlx_put_image_to_window(data->mlx, data->win, data->img.ground, 0, 0);
// 	mlx_put_image_to_window(data->mlx, data->win, data->img.ground, 64, 0);
// 	return (SUCCESS);
// }

int	render(t_data *data)
{
	int 	i;
	int 	j;
	int		w;

	i = 0;
	j = 0;
	w = 0;
	if (data->win == NULL)
		return (FAILURE);
	while (data->map_array[i] != NULL)
	{
		while (data->map_array[i][j] != '\0')
		{
			if (data->map_array[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall, w, i * IMG_SIZE);
			// else if (data->map_array[i][j] == '0')
			// 	mlx_put_image_to_window(data->mlx, data->win, data->img.ground, w, i * IMG_SIZE);
			// else if (data->map_array[i][j] == 'P')
			// 	mlx_put_image_to_window(data->mlx, data->win, data->img.player, w, i * IMG_SIZE);
			// else if (data->map_array[i][j] == 'C')
			// 	mlx_put_image_to_window(data->mlx, data->win, data->img.exit, w, i * IMG_SIZE);
			// else if (data->map_array[i][j] == 'E')
			// 	mlx_put_image_to_window(data->mlx, data->win, data->img.collectible, w, i * IMG_SIZE);
			w = w + IMG_SIZE;
			j++;
		}
		j = 0;
		w = 0;
		i++;
	}
	return (SUCCESS);
}
