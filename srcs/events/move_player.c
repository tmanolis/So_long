/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:35:09 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/17 13:24:43 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	int	i;
	int	j;

	i = data->player.p_height;
	j = data->player.p_width;
	if (data->map_array[i - 1][j] == '1')
		return ;
	if (data->map_array[i - 1][j] == 'E')
	{
		if (is_exit_opened(data) == FAILURE)
			return ;
	}
	data->map_array[i][j] = '0';
	if (data->map_array[i - 1][j] == 'C')
		data->player.coin_collected++;
	data->map_array[i - 1][j] = 'P';
	data->player.p_height = i - 1;
	data->player.moves++;
	print_moves(data);
}

void	move_down(t_data *data)
{
	int	i;
	int	j;

	i = data->player.p_height;
	j = data->player.p_width;
	if (data->map_array[i + 1][j] == '1')
		return ;
	if (data->map_array[i + 1][j] == 'E')
	{
		if (is_exit_opened(data) == FAILURE)
			return ;
	}
	data->map_array[i][j] = '0';
	if (data->map_array[i + 1][j] == 'C')
		data->player.coin_collected++;
	data->map_array[i + 1][j] = 'P';
	data->player.p_height = i + 1;
	data->player.moves++;
	print_moves(data);
}

void	move_left(t_data *data)
{
	int	i;
	int	j;

	i = data->player.p_height;
	j = data->player.p_width;
	if (data->map_array[i][j - 1] == '1')
		return ;
	if (data->map_array[i][j - 1] == 'E')
	{
		if (is_exit_opened(data) == FAILURE)
			return ;
	}
	data->map_array[i][j] = '0';
	if (data->map_array[i][j - 1] == 'C')
		data->player.coin_collected++;
	data->map_array[i][j - 1] = 'P';
	data->player.p_width = j - 1;
	data->player.moves++;
	print_moves(data);
}

void	move_right(t_data *data)
{
	int	i;
	int	j;

	i = data->player.p_height;
	j = data->player.p_width;
	if (data->map_array[i][j + 1] == '1')
		return ;
	if (data->map_array[i][j + 1] == 'E')
	{
		if (is_exit_opened(data) == FAILURE)
			return ;
	}
	data->map_array[i][j] = '0';
	if (data->map_array[i][j + 1] == 'C')
		data->player.coin_collected++;
	data->map_array[i][j + 1] = 'P';
	data->player.p_width = j + 1;
	data->player.moves++;
	print_moves(data);
}

void	move_player(t_data *data, char keypress)
{
	if (keypress == 'w')
		move_up(data);
	if (keypress == 's')
		move_down(data);
	if (keypress == 'a')
		move_left(data);
	if (keypress == 'd')
		move_right(data);
}
