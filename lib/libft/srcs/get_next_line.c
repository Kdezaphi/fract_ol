/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 10:51:02 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/02/11 13:07:34 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

int		ft_strpos(char *buf, int c)
{
	int		i;

	i = -1;
	while (buf[++i])
		if (buf[i] == c)
			return (++i);
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	long		nb_read;
	char		*tmp;
	int			new_line;

	if (!line)
		return (-1);
	tmp = ft_strdup(buf);
	*line = ft_strdup("");
	while ((new_line = ft_strpos(tmp, '\n')) == -1)
	{
		*line = ft_dup_join(*line, tmp);
		if ((nb_read = (long)read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		else if (nb_read == 0 && buf[0] == '\0' && *line[0] == '\0')
			return (0);
		else if (nb_read == 0 && buf[0] == '\0')
			return (1);
		buf[nb_read] = '\0';
		tmp = ft_strdup(buf);
	}
	tmp[new_line - 1] = (new_line > 0) ? 0 : tmp[new_line - 1];
	*line = ft_dup_join(*line, tmp);
	ft_strcpy(buf, &buf[new_line]);
	return (1);
}
