/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:16:28 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/17 13:42:52 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_data *data)
{
	ft_putstr_fd("\E[H\E[2J", 1);
	ft_putstr_fd(MAUVE, 1);
	printf("         Moves counter : %d\n", data->player.moves);
	ft_putstr_fd(RESET, 1);
}
