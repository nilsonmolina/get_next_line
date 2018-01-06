/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:55:23 by nmolina           #+#    #+#             */
/*   Updated: 2018/01/04 20:15:53 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_memory	mem[1024];
	t_memory		curr;
	char			*tmp;

	curr = mem[fd];
	if (!curr.buf)
		read_file(fd, &curr);
	if (!line)
		line = (char *)malloc(sizeof(char));
	while (curr.buf[curr.head] != '/n')
	{
		if (curr.buf[curr.head++] == '\0')
		{
			line = ft_strjoin(line, curr.buf);
			read_file(fd, &curr);
			curr.head = 0;
		}
	}
	return (1);
}

void	read_file(const int fd, t_memory *mem)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];

	ret = read(fd, mem->buf, BUFF_SIZE);
	mem->buf[ret] == '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		index;
	int		iterator;

	if (!(s1 && s2))
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!str)
		return (NULL);
	index = 0;
	iterator = 0;
	while (s1[iterator])
		str[index++] = s1[iterator++];
	iterator = 0;
	while (s2[iterator])
		str[index++] = s2[iterator++];
	str[index] = '\0';
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