/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:56:35 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/09 14:41:29 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_it_a_ber_file(char *str)
{
	int	ext_index;

	ext_index = ft_strlen(str) - 4;
	printf("ext_index : %d\nchar a l'index : %c\n", ext_index, *(str + ext_index));
	return (1);
}

void parse_the_map(char *str)
{
	(void)str;
}

int	get_the_map(int argc, char **argv)
{
	if (argc != 2)
		return (print_error("usage : ./solong maps/<map>.ber"));
	if (is_it_a_ber_file(argv[1]) == SUCCESS)
		parse_the_map(argv[1]);
	else
		return (print_error("the map needs to be with the .ber extension."));
	return (SUCCESS);
}
