/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:48:10 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/09 17:43:18 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(t_data *data)
{
	(void)data;
	return (1);
}

int	init_map(char *str, t_data *data)
{
	data->map.map_path = str;
	data->map.fd = open(str, O_RDONLY);
	if (data->map.fd < 0)
		return (FAILURE);
	else
		close(data->map.fd);
	data->map.nb_line = count_line(data);
	return (SUCCESS);
}
