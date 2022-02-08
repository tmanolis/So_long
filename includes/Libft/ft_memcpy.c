/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:13:09 by tmanolis          #+#    #+#             */
/*   Updated: 2021/06/28 14:47:32 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_cast;
	unsigned char	*src_cast;

	i = 0;
	dst_cast = (unsigned char *)dst;
	src_cast = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*dst_cast = *src_cast;
		dst_cast++;
		src_cast++;
		i++;
	}
	return (dst);
}
