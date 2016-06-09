/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:26:25 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 11:20:24 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padnotype(t_flags *flags)
{
	int		i;
	char	pad;

	i = flags->size;
	if (flags->neg)
		while (--i > 0)
			write(flags->fd, " ", 1);
	else
	{
		pad = (flags->zero) ? '0' : ' ';
		while (--i > 0)
			write(flags->fd, &pad, 1);
	}
}

char	*ft_paddposflag(char *tmp, t_flags *flags)
{
	char	*str;
	char	*sign;

	if (flags->pos)
		sign = ft_strdup("+");
	else
		sign = ft_strdup(" ");
	str = ft_dup_join(sign, tmp);
	if (flags->size > (int)ft_strlen(str))
		return (ft_paddneg(str, flags));
	else
		return (str);
}

char	*ft_paddpos(char *tmp, t_flags *flags)
{
	char	*str;
	char	*pad;
	int		i;

	i = -1;
	if ((flags->pos || flags->space) && flags->size > (int)ft_strlen(tmp))
		return (ft_paddposflag(tmp, flags));
	pad = (char*)malloc(flags->size - ft_strlen(tmp) + 1);
	if (flags->zero && !flags->neg && flags->pre == -1)
		while (++i < flags->size - (int)ft_strlen(tmp))
			pad[i] = '0';
	else
		while (++i < flags->size - (int)ft_strlen(tmp))
			pad[i] = ' ';
	pad[i] = '\0';
	if (flags->neg)
		str = ft_strjoin(tmp, pad);
	else
		str = ft_strjoin(pad, tmp);
	free(pad);
	free(tmp);
	return (str);
}
