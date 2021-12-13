/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:00:04 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/13 15:24:36 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win == NULL)
		return (1);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 64, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	get_the_map(argc, argv, &data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (data.win == NULL)
	{
		free(data.win);
		return (MLX_ERROR);
	}

	data.img.img = mlx_xpm_file_to_image(data.mlx, "assets/test.xpm", &data.img.width, &data.img.height);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(data.mlx, data.img.img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	free_map_array(data.map_array, (data.map.nb_line - 1));
}
