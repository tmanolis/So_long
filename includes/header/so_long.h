/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:31:04 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/08 18:47:06 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../../mlx_linux/mlx.h"
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
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

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_data;

typedef struct	s_img
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}				t_rect;

#endif