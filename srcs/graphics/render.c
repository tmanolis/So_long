/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:09:56 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/16 18:52:44 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall(t_data *data, int i, int j, int w)
{
	if (i == 0 && (j > 0 && j < (data->map.nb_column - 1)))
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_top, w, \
		i * IMG_SIZE);
	else if (j == 0 && (i > 0 && i < (data->map.nb_line - 1)))
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_left, w, \
		i * IMG_SIZE);
	else if (j == (data->map.nb_column - 1)
		&& (i > 0 && i < (data->map.nb_line - 1)))
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_right, w, \
		i * IMG_SIZE);
	else if (i == (data->map.nb_line - 1) && j == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_l_d_c, w, \
		i * IMG_SIZE);
	else if (i == 0 && j == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_l_t_c, w, \
		i * IMG_SIZE);
	else if (i == 0 && j == (data->map.nb_column - 1))
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_r_t_c, w, \
		i * IMG_SIZE);
	else if (i == (data->map.nb_line - 1) && j == (data->map.nb_column - 1))
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_r_d_c, w, \
		i * IMG_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_down, w, \
		i * IMG_SIZE);
}

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
			// if (data->map_array[i][j] == '1')
				// mlx_put_image_to_window(data->mlx, data->win, data->img.wall, w, i * IMG_SIZE);
			if (data->map_array[i][j] == '1')
				render_wall(data, i, j, w);
			else if (data->map_array[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img.ground, w, i * IMG_SIZE);
			else if (data->map_array[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img.player, w, i * IMG_SIZE);
			else if (data->map_array[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img.collectible, w, i * IMG_SIZE);
			else if (data->map_array[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img.exit, w, i * IMG_SIZE);
			w = w + IMG_SIZE;
			j++;
		}
		j = 0;
		w = 0;
		i++;
	}
	// mlx_string_put(data->mlx, data->win, 15, 15, 231, "Counter:");
    // mlx_string_put(data->mlx, data->win, 80, 15, 231, ft_itoa(data->player.moves));
	return (SUCCESS);
}
