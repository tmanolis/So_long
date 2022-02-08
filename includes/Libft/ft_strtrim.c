/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:35:51 by tmanolis          #+#    #+#             */
/*   Updated: 2021/06/29 19:17:22 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	return (start);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end]) && end > 0)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*s1_trim;

	if (!set || !s1)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (ft_strlen(s1) == 0 || (start == ft_strlen(s1) && end == 0))
		return (ft_strdup(""));
	s1_trim = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!s1_trim)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		s1_trim[i] = s1[start];
		i++;
		start++;
	}
	s1_trim[i] = '\0';
	return (s1_trim);
}
