/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:31:04 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/14 16:27:49 by tmanolis         ###   ########.fr       */
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

# define IMG_SIZE 48

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF


typedef struct	s_img
{
	int		width;
	int		height;
	void	*wall;
	void	*ground;
	void	*player;
	void	*collectible;
	void	*exit;
}				t_img;

typedef struct	s_map
{
	char	*map_path;
	int		nb_line;
	int		nb_column;
	int		player;
	int		collectible;
	int		exit;
}				t_map;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	char	**map_array;
	t_img	img;
	t_map	map;
}				t_data;

// GET_MAP --- check_map_errors
int		check_map_error(t_data *data);
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


#endif