/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_sides_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:11:20 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/17 14:15:28 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top_or_bottom(t_data *data, int i, int j)
{
	while (data->map_array[i][j])
	{
		if (data->map_array[i][j] != '1')
			return (FAILURE);
		j++;
	}
	return (SUCCESS);
}

int	check_map_sides(t_data *data)
{
	int	i;
	int	j;

	if (check_top_or_bottom(data, 0, 0) == FAILURE)
		return (FAILURE);
	i = 1;
	j = data->map.nb_column - 1;
	while (i < (data->map.nb_line - 1))
	{
		if (data->map_array[i][0] != '1' || data->map_array[i][j] != '1')
			return (FAILURE);
		i++;
	}
	if (check_top_or_bottom(data, i, 0) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
