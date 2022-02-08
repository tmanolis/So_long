/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:52:30 by tmanolis          #+#    #+#             */
/*   Updated: 2021/06/28 14:42:01 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	occurence;
	unsigned char	*str;

	i = 0;
	occurence = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == occurence)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
