/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:31:04 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/09 12:14:05 by tmanolis         ###   ########.fr       */
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


typedef struct	s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_data;



#endif