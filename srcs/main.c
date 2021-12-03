#include <stdlib.h>
#include "../mlx_linux/mlx.h"
#include "so_long.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	usleep(10000000);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
