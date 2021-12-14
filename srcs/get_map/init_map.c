/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:48:10 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/14 13:40:29 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(t_data *data)
{
	int		nb_line;
	int		fd;
	char	*line;

	nb_line = 0;
	fd = open(data->map.map_path, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nb_line);
}

int	fill_line(t_data *data, char *line, int row)
{
	int	i;
	int	size;

	i = 0;
	if (ft_strchr(line, '\n'))
		size = ft_strlen(line);
	else
		size = ft_strlen(line) + 1;
	data->map_array[row] = (char *)malloc(sizeof(char) * size);
	if (!data->map_array[row])
	{
		free_map_array(data->map_array, row);
		return (FAILURE);
	}
	while (line[i] != '\n' && line[i] != '\0')
	{
		data->map_array[row][i] = line[i];
		i++;
	}
	data->map_array[row][i] = '\0';
	return (SUCCESS);
}

int	fill_the_map(t_data *data)
{
	int		row;
	int		fd;
	char	*line;

	fd = open(data->map.map_path, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	line = get_next_line(fd);
	data->map.nb_column = ft_strlen(line) - 1;
	row = 0;
	while (line)
	{
		if (fill_line(data, line, row) == FAILURE)
			return (FAILURE);
		free(line);
		line = get_next_line(fd);
		row++;
	}
	data->map_array[row] = NULL;
	close(fd);
	return (SUCCESS);
}

int	init_map(char *line, t_data *data)
{
	data->map.map_path = line;
	data->map.nb_line = count_line(data);
	if (!data->map.nb_line)
		return (FAILURE);
	data->map_array = (char **)malloc(sizeof(char *) * (data->map.nb_line + 1));
	if (!data->map_array)
		return (FAILURE);
	if (fill_the_map(data) == FAILURE)
		return (FAILURE);
	data->win_width = IMG_SIZE * data->map.nb_column;
	data->win_height = IMG_SIZE * data->map.nb_line;
	return (SUCCESS);
}
