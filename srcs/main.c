#include <stdlib.h>
#include "../mlx_linux/mlx.h"
#include "so_long.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

// int main(void)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
// 	usleep(10000000);
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// 	mlx_destroy_display(mlx_ptr);
// 	free(mlx_ptr);
// }

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	mlx_close(int keycode, t_vars *vars)
{
	printf("key press:%d\n", keycode);
	if (keycode == 65307) //65307==echap
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (1);
}

int	key_release(int keycode, t_vars *vars)
{
	printf("key release:%d\n", keycode);
	(void)vars;
	return (1);
}

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");

// 	mlx_hook(vars.win, 2, 1L<<0, mlx_close, &vars);
// 	// mlx_hook(vars.win, 3, 1L<<1, key_release, &vars);
// 	mlx_loop(vars.mlx);
// }

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	 
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, mlx_close, &vars);
	mlx_loop(vars.mlx);
}
