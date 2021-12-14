/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:58:56 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/14 19:55:18 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *str)
{
	printf("Error\n%s\n", str);
	return (FAILURE);
}

void	free_map_array(char **map_array, int i)
{
	while (i >= 0)
	{
		free(map_array[i]);
		i--;
	}
	free(map_array);
}

void	destroy_mlx_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.ground);
	mlx_destroy_image(data->mlx, data->img.player);
}

void	endgame(t_data *data)
{
	destroy_mlx_imgs(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map_array(data->map_array, (data->map.nb_line - 1));
}