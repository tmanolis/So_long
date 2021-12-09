/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:31:04 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/09 17:42:05 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
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

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF


typedef struct	s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct	s_map
{
	char	*map_path;
	int		fd;
	int		nb_line;
}				t_map;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
}				t_data;

// GET_MAP --- get_the_map
int	get_the_map(int argc, char **argv, t_data *data);
// GET_MAP --- init_map
int	init_map(char *str, t_data *data);
// UTILS --- errors_and_free
int	print_error(char *str);


#endif