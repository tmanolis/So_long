/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:05:05 by tmanolis          #+#    #+#             */
/*   Updated: 2021/06/29 15:08:12 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_while_you_can(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

static int	wordcount(char const *s, char c)
{
	int			i;
	static int	count;

	i = 0;
	count = 0;
	if (ft_strchr(s, c) == 0)
	{
		return (count + 1);
	}
	while (s[i] != '\0')
	{
		if (s[i] != c && ((s[i + 1] == c || s[i + 1] == '\0')))
			count++;
		i++;
	}
	return (count);
}

static char	*wordcopy(char const *s, char c)
{
	int		i;
	int		letter;
	char	*line;

	letter = 0;
	while (s[letter] != c && s[letter] != '\0')
	{
		letter++;
	}
	line = (char *)malloc(sizeof(char) * (letter + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < letter)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	**do_the_split(char **split, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			split[i] = wordcopy(s, c);
			if (!split[i])
			{
				free_while_you_can(split, i);
				return (NULL);
			}
			i++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!split)
		return (NULL);
	split = do_the_split(split, s, c);
	return (split);
}
