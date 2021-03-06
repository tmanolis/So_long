/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:31:04 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/17 14:15:10 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "get_next_line.h"
# include "../../mlx_linux/mlx.h"
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define SUCCESS 1
# define FAILURE 0

# define IMG_SIZE 75

# define MLX_ERROR 1

# define MAUVE "\033[38;5;98m"
# define RESET "\033[0m"

typedef struct s_img
{
	int		width;
	int		height;
	void	*wall_top;
	void	*wall_down;
	void	*wall_left;
	void	*wall_right;
	void	*wall_l_d_c;
	void	*wall_l_t_c;
	void	*wall_r_t_c;
	void	*wall_r_d_c;
	void	*ground;
	void	*player;
	void	*collectible;
	void	*exit;
	char	*display_moves;
}				t_img;

typedef struct s_map
{
	char	*map_path;
	int		nb_line;
	int		nb_column;
	int		player;
	int		collectible;
	int		exit;
}				t_map;

typedef struct s_player
{
	int		p_height;
	int		p_width;
	int		moves;
	int		coin_collected;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	char		**map_array;
	t_img		img;
	t_map		map;
	t_player	player;
}				t_data;

// EVENTS --- check_before_moving
int		is_exit_opened(t_data *data);
// EVENTS --- handle
int		handle_exit_button(t_data *data);
int		handle_keypress(int keysym, t_data *data);
// EVENTS --- move_player
void	move_player(t_data *data, char keypress);
// GET_MAP --- check_map_errors
int		check_map_error(t_data *data);
// GET_MAP --- check_map_sides_errors
int		check_map_sides(t_data *data);
// GET_MAP --- get_the_map
int		get_the_map(int argc, char **argv, t_data *data);
// GET_MAP --- init_map
int		init_map(char *str, t_data *data);
// GRAPHICS --- get_images
void	get_images(t_data *data);
// GRAPHICS --- render
int		render(t_data *data);
// UTILS --- errors_and_free
int		print_error(char *str);
void	free_map_array(char **map_array, int i);
void	endgame(t_data *data);
// UTILS --- print_moves
void	print_moves(t_data *data);

#endif