/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:56:35 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/09 18:53:57 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_it_a_ber_file(char *str)
{
	// int fd;
	int	ext_index;

	// fd = open(str, O_DIRECTORY);
	// if (fd)
	// {
	// 	close(fd);
	// 	return (FAILURE);
	// }
	ext_index = ft_strlen(str) - 4;
	if (ft_strncmp((str + ext_index), ".ber", 4) == 0)
		return (SUCCESS);
	else
		return (FAILURE);
}

int	parse_the_map(char *str, t_data *data)
{

	if (init_map(str, data) == FAILURE)
		return (FAILURE);
	// if (check_map_error == SUCCESS) etc...
	return (SUCCESS);
}

int	get_the_map(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		return (print_error("usage : ./solong maps/<map>.ber"));
	if (is_it_a_ber_file(argv[1]) == FAILURE)
		return (print_error("The map is not a file with .ber extension."));
	if (parse_the_map(argv[1], data) == FAILURE)
		return (print_error("The map is incorrect."));
	return (SUCCESS);
}
