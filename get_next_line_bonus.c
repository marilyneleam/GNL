/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:34:07 by mleam             #+#    #+#             */
/*   Updated: 2021/01/23 16:17:24 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*before_line(char *str)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	if (!(rest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	i++;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*after_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*stock[OPEN_MAX];
	int			ret;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, 0, 0) == -1)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!back_line(stock[fd]) && ret != 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		stock[fd] = ft_strjoin(stock[fd], buf);
	}
	free(buf);
	*line = after_line(stock[fd]);
	stock[fd] = before_line(stock[fd]);
	if (ret == 0)
		return (ret);
	return (1);
}
