/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:34:56 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/17 13:27:35 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_is_a_rectangle(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.nb_line < 3)
		return (print_error("The map should at least have 3 lines."));
	while (data->map_array[i])
	{
		if ((int)ft_strlen(data->map_array[i]) != data->map.nb_column)
			return (print_error("The map is not a rectangle."));
		i++;
	}
	return (SUCCESS);
}

int	check_map_sides(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map_array[0][j])
	{
		if (data->map_array[0][j] != '1')
			return (FAILURE);
		j++;
	}
	i = 1;
	j = data->map.nb_column - 1;
	while (i < (data->map.nb_line - 1))
	{
		if (data->map_array[i][0] != '1' || data->map_array[i][j] != '1')
			return (FAILURE);
		i++;
	}
	j = 0;
	while (data->map_array[i][j])
	{
		if (data->map_array[i][j] != '1')
			return (FAILURE);
		j++;
	}
	return (SUCCESS);
}

int	check_letters(t_data *data)
{
	int	i;
	int	j;

	data->map.player = 0;
	data->map.collectible = 0;
	data->map.exit = 0;
	i = 0;
	while (data->map_array[i])
	{
		j = 0;
		while (data->map_array[i][j])
		{
			if (ft_strchr("10PCE", data->map_array[i][j]) == FAILURE)
				return (print_error("There is an unvalid letter in the map."));
			if (data->map_array[i][j] == 'P')
				data->map.player++;
			if (data->map_array[i][j] == 'C')
				data->map.collectible++;
			if (data->map_array[i][j] == 'E')
				data->map.exit++;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_params(t_data *data)
{
	if (data->map.player != 1)
		return (print_error("The map should have ONE player."));
	else if (data->map.collectible < 1)
		return (print_error("The map needs at least one collectible."));
	else if (data->map.exit != 1)
		return (print_error("The map should have ONE exit."));
	else
		return (SUCCESS);
}

int	check_map_error(t_data *data)
{
	if (check_map_is_a_rectangle(data) == FAILURE)
		return (FAILURE);
	if (check_map_sides(data) == FAILURE)
		return (print_error("The map must be closed/surrounded by walls."));
	if (check_letters(data) == FAILURE)
		return (FAILURE);
	if (check_params(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
