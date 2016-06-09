/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:12:21 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 11:21:37 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_paddingchar(t_flags *flags)
{
	char	*pad;
	int		i;

	i = -1;
	pad = (char*)malloc(flags->size);
	if (flags->zero && !flags->neg)
		while (++i < flags->size - 1)
			pad[i] = '0';
	else
		while (++i < flags->size - 1)
			pad[i] = ' ';
	pad[i] = '\0';
	return (pad);
}

int		ft_padczero(t_flags *flags)
{
	char	*pad;
	int		i;

	i = -1;
	pad = (char*)malloc(flags->size - 1);
	if (flags->zero && !flags->neg)
		while (++i < flags->size - 1)
			pad[i] = '0';
	else
		while (++i < flags->size - 1)
			pad[i] = ' ';
	pad[i] = '\0';
	if (flags->neg)
	{
		write(flags->fd, "\0", 1);
		write(flags->fd, pad, ft_strlen(pad));
	}
	else
	{
		write(flags->fd, pad, ft_strlen(pad));
		write(flags->fd, "\0", 1);
	}
	free(pad);
	return (flags->size);
}

int		ft_affichec(char c, t_flags *flags)
{
	char	*pad;

	if (c == 0 && flags->size)
		return (ft_padczero(flags));
	if (flags->size > 1)
	{
		pad = ft_paddingchar(flags);
		if (!flags->neg)
			write(flags->fd, pad, ft_strlen(pad));
		write(flags->fd, &c, 1);
		if (flags->neg)
			write(flags->fd, pad, ft_strlen(pad));
		free(pad);
		return (flags->size);
	}
	write(flags->fd, &c, 1);
	return (1);
}
