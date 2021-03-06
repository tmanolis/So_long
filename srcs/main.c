/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:00:04 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/17 12:12:46 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (get_the_map(argc, argv, &data) == FAILURE)
		return (FAILURE);
	else
	{
		data.mlx = mlx_init();
		if (data.mlx == NULL)
			return (MLX_ERROR);
		data.win = mlx_new_window(data.mlx, data.win_width, \
		data.win_height, "Moumi Moon");
		if (data.win == NULL)
		{
			free(data.win);
			return (MLX_ERROR);
		}
		get_images(&data);
		mlx_loop_hook(data.mlx, &render, &data);
		mlx_hook(data.win, ClientMessage, LeaveWindowMask, \
		&handle_exit_button, &data);
		mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
		mlx_loop(data.mlx);
		endgame(&data);
	}
	return (SUCCESS);
}
