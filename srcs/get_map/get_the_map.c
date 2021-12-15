/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:56:35 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/15 13:52:11 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_it_a_ber_file(char *str)
{
	int	fd;
	int	ext_index;

	fd = open(str, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (FAILURE);
	}
	ext_index = ft_strlen(str) - 4;
	if (ft_strncmp((str + ext_index), ".ber", 4) == 0)
		return (SUCCESS);
	else
		return (FAILURE);
}

int	parse_the_map(char *str, t_data *data)
{
	if (init_map(str, data) == FAILURE)
		return (print_error("Couldn't initialize the map."));
	if (check_map_error(data) == FAILURE)
	{
		free_map_array(data->map_array, (data->map.nb_line - 1));
		return (FAILURE);
	}
	return (SUCCESS);
}

void	init_player_position(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (data->map_array[i])
	{
		j = 0;
		while (data->map_array[i][j])
		{
			if (data->map_array[i][j] == 'P')
			{
				data->player.p_height = i;
				data->player.p_width = j;
			}
			j++;
		}
		i++;
	}
	data->player.moves = 0;
	data->player.coin_collected = 0;
}

int	get_the_map(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		return (print_error("usage : ./solong maps/<map>.ber"));
	if (is_it_a_ber_file(argv[1]) == FAILURE)
		return (print_error("The map is not a file with .ber extension."));
	if (parse_the_map(argv[1], data) == FAILURE)
		return (FAILURE);
	init_player_position(data);
	return (SUCCESS);
}
