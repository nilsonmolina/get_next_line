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

int		get_next_line(const int fd, char **line)
{
	static t_history	io[1024];

	read_file(fd, &io[fd]);

}

void	read_file(const int fd, t_history *io)
{
	int		ret;
	char	*temp;

	if (io || io.buffer[io.head] == '\0')
	{
		temp = (char *)malloc(sizeof(char *) * (BUFF_SIZE + 1))
		ret = read(fd, io.buffer, BUFF_SIZE);
		free(io.buffer);
		io.buffer[ret] = '\0';
	}
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
