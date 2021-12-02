/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:31:04 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/02 18:57:36 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SUCCESS 1
# define FAILURE 0

# include "../Libft/libft.h"
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	t_list		*lst_a;
	t_list		*lst_b;
	size_t		len;
	long int	*array_tmp;
}				t_data;



#endif