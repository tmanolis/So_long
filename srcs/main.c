/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:00:04 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/09 12:14:23 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main(void)
// {
// 	void	*mlx;
// 	void	*win;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
// 	usleep(10000000);
// 	mlx_destroy_window(mlx, win);
// 	mlx_destroy_display(mlx);
// 	free(mlx);
// }


// int	mlx_close(int keycode, t_vars *vars)
// {
// 	printf("key press:%d\n", keycode);
// 	if (keycode == 65307) // 65307==echap
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		mlx_destroy_display(vars->mlx);
// 		free(vars->mlx);
// 		exit(0);
// 	}
// 	return (1);
// }

// int	key_release(int keycode, t_vars *vars)
// {
// 	printf("key release:%d\n", keycode);
// 	(void)vars;
// 	return (1);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");

// 	mlx_hook(vars.win, 2, 1L<<0, mlx_close, &vars);
// 	// mlx_hook(vars.win, 3, 1L<<1, key_release, &vars);
// 	mlx_loop(vars.mlx);
// }


// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	t_data	img;
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
// 	img.img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 	mlx_hook(vars.win, 2, 1L<<0, mlx_close, &vars);
// 	mlx_loop(vars.mlx);
// }


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

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (data.win == NULL)
	{
		free(data.win);
		return (MLX_ERROR);
	}

	data.img.img = mlx_xpm_file_to_image(data.mlx, "/mnt/nfs/homes/tmanolis/Documents/So_long/assets/test.xpm", &data.img.width, &data.img.height);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(data.mlx, data.img.img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
