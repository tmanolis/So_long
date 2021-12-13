/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:33:02 by tmanolis          #+#    #+#             */
/*   Updated: 2021/12/13 14:45:00 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copy_until_eol(char *stock)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i] == '\n')
		i++;
	len = i;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	get_the_spare(char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\n')
		i++;
	i = i + 1;
	while (i < BUFFER_SIZE)
	{
		buf[j] = buf[i];
		j++;
		i++;
	}
	buf[j] = '\0';
}

char	*get_next_line_2(size_t ret, char *stock, char *buf)
{
	char	*line;

	line = NULL;
	if (*stock == '\0')
	{
		free(stock);
		return (NULL);
	}
	if (ret > 0)
	{
		line = copy_until_eol(stock);
		free(stock);
		get_the_spare(buf);
	}
	else
	{
		line = copy_until_eol(stock);
		free(stock);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	size_t		ret;
	char		*stock;
	static char	buf[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (NULL);
	stock = NULL;
	stock = ft_strjoin_gnl(stock, buf);
	ret = 1;
	while (ret > 0 && ft_strchr_gnl(stock, '\n') == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(stock);
			return (NULL);
		}
		buf[ret] = '\0';
		stock = ft_strjoin_gnl(stock, buf);
	}
	return (get_next_line_2(ret, stock, buf));
}
