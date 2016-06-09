/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 10:42:23 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 12:34:08 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_paddingstr(char *tmp, t_flags *flags)
{
	char	*pad;
	int		i;
	int		len;

	i = -1;
	len = flags->size - (int)ft_strlen(tmp);
	pad = (char*)malloc(len + 1);
	if (flags->zero && !flags->neg)
		while (++i < len)
			pad[i] = '0';
	else
		while (++i < len)
			pad[i] = ' ';
	pad[i] = '\0';
	if (!flags->neg)
		return (ft_dup_join(pad, tmp));
	return (ft_dup_join(tmp, pad));
}

int		ft_affiches(char *str, t_flags *flags)
{
	char	*tmp;
	int		i;

	i = -1;
	if (!str)
		str = "(null)";
	if (flags->pre > -1 && flags->pre < (int)ft_strlen(str))
	{
		tmp = (char*)malloc(flags->pre + 1);
		while (++i < flags->pre)
			tmp[i] = str[i];
		tmp[i] = '\0';
	}
	else
		tmp = ft_strdup(str);
	if (flags->size > (int)ft_strlen(tmp))
		tmp = ft_paddingstr(tmp, flags);
	write(flags->fd, tmp, ft_strlen(tmp));
	i = ft_strlen(tmp);
	free(tmp);
	return (i);
}
