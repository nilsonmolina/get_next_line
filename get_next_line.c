/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:55:23 by nmolina           #+#    #+#             */
/*   Updated: 2018/01/12 17:25:01 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_memory	mem[1024];
	t_memory		scan;

	scan = mem[fd];
	if (!scan.buf[0])
		read_file(fd, &scan);
	*line = (char *)malloc(sizeof(char));
	*line[0] = '\0';
	while (scan.buf[scan.head] != '\n')
	{
		if (scan.buf[scan.head] == '\0')
			read_file(fd, &scan);
		else
			*line = ft_straddchar(line, scan.buf[scan.head]);
		scan.head++;
	}
	scan.head++;
	return (1);
}

void	read_file(const int fd, t_memory *mem)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];

	ret = read(fd, mem->buf, BUFF_SIZE);
	mem->buf[ret] = '\0';
	mem->head = 0;
}

char	*ft_straddchar(char **src, char c)
{
	char	*str;
	int		index;

	if (!(src && c))
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (ft_strlen(*src) + 2));
	if (!str)
		return (NULL);
	index = -1;
	while (src[++index])
		str[index] = *src[index];
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

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	char	*line;

	if (argc != 2)
		return (1);
	get_next_line(open(argv[1], O_RDONLY), &line);
	ft_putstr(line);
	return (0);
}
