/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:29:56 by tmanolis          #+#    #+#             */
/*   Updated: 2021/06/29 15:12:07 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	

static int	count_unit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (count + 1);
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			i;
	int			count;
	long int	nb;
	char		*str;

	nb = (long int)n;
	count = count_unit(nb);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		str[i] = '-';
		nb = nb * -1;
		i++;
	}
	str[count] = '\0';
	while (i < count)
	{
		str[--count] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
