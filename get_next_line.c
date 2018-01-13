/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:55:23 by nmolina           #+#    #+#             */
/*   Updated: 2018/01/12 22:36:59 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_memory	mem[4096];
	t_memory		*file;
	int				ret;

	if (fd > 4096 || fd < 0 || !line)
		return (-1);
	file = &mem[fd];
	*line = (char *)malloc(sizeof(char));
	if (!*line)
		return (-1);
	*line[0] = '\0';
	while (file->buf[file->head] != '\n')
	{
		if (file->buf[file->head] == '\0')
		{
			ret = read_file(fd, file);
			if (ret == -1)
				return (-1);
			if (ret == 0 && !*line[0])
				return (0);
			if (ret == 0 && *line[0])
				return (1);
		}
		if (file->buf[file->head] != '\n')
			*line = ft_straddchar(*line, file->buf[file->head]);
		file->head++;
	}
	file->head++;
	return (1);
}

int		read_file(const int fd, t_memory *file)
{
	int		ret;
	ret = read(fd, file->buf, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	file->buf[ret] = '\0';
	file->head = 0;
	return (ret);
}

char	*ft_straddchar(char *src, char c)
{
	char	*str;
	int		index;

	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 2));
	if (!str)
		return (NULL);
	index = 0;
	while (src[index])
	{
		str[index] = src[index];
		index++;
	}
	str[index++] = c;
	str[index] = '\0';
	free(src);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
