/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:14:02 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 11:21:43 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_paddneg(char *tmp, t_flags *flags)
{
	char	*pad;
	char	*str;
	char	c;
	int		i;

	i = -1;
	pad = (char*)malloc(flags->size - ft_strlen(tmp) + 1);
	if (flags->zero && !flags->neg && flags->pre == -1)
		while (++i < flags->size - (int)ft_strlen(tmp))
			pad[i] = '0';
	else
		while (++i < flags->size - (int)ft_strlen(tmp))
			pad[i] = ' ';
	pad[i] = '\0';
	if (flags->zero && flags->pre == -1 && !flags->neg)
	{
		c = tmp[0];
		tmp[0] = pad[0];
		pad[0] = c;
	}
	str = (flags->neg) ? ft_dup_join(tmp, pad) : ft_dup_join(pad, tmp);
	return (str);
}

char	*ft_prenum(char *str, int diff)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char*)malloc(ft_strlen(str) + diff + 1);
	if (str[j] == '-')
	{
		j = 1;
		diff++;
		tmp[i++] = '-';
	}
	while (i < diff)
		tmp[i++] = '0';
	while (str[j])
		tmp[i++] = str[j++];
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

int		ft_affichedneg(long long nb, t_flags *flags)
{
	char	*tmp;
	int		res;

	tmp = ft_lltoa(nb);
	if (flags->pre >= (int)ft_strlen(tmp))
		tmp = ft_prenum(tmp, flags->pre - ft_strlen(tmp) + 1);
	if (flags->size > (int)ft_strlen(tmp))
		tmp = ft_paddneg(tmp, flags);
	write(flags->fd, tmp, ft_strlen(tmp));
	res = ft_strlen(tmp);
	free(tmp);
	return (res);
}

char	*ft_pos_space_flag(char *tmp, int pos, int space)
{
	char *sign;

	sign = NULL;
	if (pos)
		sign = ft_strdup("+");
	else if (space)
		sign = ft_strdup(" ");
	return (ft_dup_join(sign, tmp));
}

int		ft_affiched(long long nb, t_flags *flags)
{
	char	*tmp;
	int		res;

	if (nb < 0)
		return (ft_affichedneg(nb, flags));
	tmp = ft_lltoa(nb);
	if (flags->pre > (int)ft_strlen(tmp))
		tmp = ft_prenum(tmp, flags->pre - ft_strlen(tmp));
	if (flags->pre == 0 && nb == 0)
	{
		free(tmp);
		if (flags->size)
			tmp = ft_strdup("");
		else
			return (0);
	}
	if (flags->size > (int)ft_strlen(tmp))
		tmp = ft_paddpos(tmp, flags);
	else if (flags->pos || flags->space)
		tmp = ft_pos_space_flag(tmp, flags->pos, flags->space);
	write(flags->fd, tmp, ft_strlen(tmp));
	res = ft_strlen(tmp);
	free(tmp);
	return (res);
}
