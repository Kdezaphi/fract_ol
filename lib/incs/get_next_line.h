/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:25:30 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/12/11 14:58:14 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000000

int				get_next_line(const int fd, char **line);

typedef struct	s_gnl
{
	int				fd;
	char			buf[BUFF_SIZE + 1];
	struct s_gnl	*next;
}				t_gnl;

#endif
