/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:45:02 by nmolina           #+#    #+#             */
/*   Updated: 2018/01/04 19:53:03 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 32

typedef struct	s_history
{
	char	*buffer[BUFF_SIZE + 1];
	int		head;
}				t_history;

int		get_next_line(const int fd, char **line);
