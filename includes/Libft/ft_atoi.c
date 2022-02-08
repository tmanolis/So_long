/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:29:56 by tmanolis          #+#    #+#             */
/*   Updated: 2021/05/26 14:50:59 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	value = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = 1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		value = value * 10 + (str[i] - 48);
		i++;
	}
	if (j == 1)
		return (value * -1);
	else
		return (value);
}
