/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_before_moving.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:44:44 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/15 16:29:55 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_exit_opened(t_data *data)
{
	int i;
	int	j;

	i = data->player.p_height;
	j = data->player.p_width;
	if (data->player.coin_collected == data->map.collectible)
	{
		data->map_array[i][j] = '0';
		data->map_array[i - 1][j] = 'P';
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		return (SUCCESS);
	}
	else
		return (FAILURE);
}
