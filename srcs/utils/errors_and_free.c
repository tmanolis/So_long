/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:58:56 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/13 14:02:25 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *str)
{
	printf("Error\n%s\n", str);
	return (FAILURE);
}

void	free_map_array(char **map_array, int i)
{
	while (i >= 0)
	{
		free(map_array[i]);
		i--;
	}
	free(map_array);
}