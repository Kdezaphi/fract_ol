/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:15:46 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 12:34:35 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convpad(char *tmp, char *pad)
{
	char	*padconv;
	char	*test;
	int		i;
	int		j;

	padconv = (char*)malloc(ft_strlen(pad) + 3);
	padconv[0] = tmp[0];
	padconv[1] = tmp[1];
	i = 2;
	j = 0;
	while (pad[j])
		padconv[i++] = pad[j++];
	padconv[i] = '\0';
	test = ft_strdup(&tmp[2]);
	free(tmp);
	return (ft_dup_join(padconv, test));
}

char	*ft_padxsharp(char *tmp, t_flags *flags)
{
	char	*pad;
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
	if (flags->neg)
		return (ft_dup_join(tmp, pad));
	else if (flags->zero && flags->pre == -1)
		return (ft_convpad(tmp, pad));
	return (ft_dup_join(pad, tmp));
}

char	*ft_padx(char *tmp, t_flags *flags)
{
	char	*str;
	char	*pad;
	int		i;

	i = -1;
	if (flags->sharp)
		return (ft_padxsharp(tmp, flags));
	pad = (char*)malloc(flags->size - ft_strlen(tmp) + 1);
	if (flags->zero && !flags->neg && flags->pre == -1)
		while (++i < flags->size - (int)ft_strlen(tmp))
			pad[i] = '0';
	else
		while (++i < flags->size - (int)ft_strlen(tmp))
			pad[i] = ' ';
	pad[i] = '\0';
	if (flags->neg)
		str = ft_dup_join(tmp, pad);
	else
		str = ft_dup_join(pad, tmp);
	return (str);
}

char	*ft_sharpx(char c, unsigned long long nb, char *tmp)
{
	char	*sharp;

	if (c == 'p' || (c == 'x' && nb != 0))
	{
		sharp = ft_strdup("0x");
		tmp = ft_dup_join(sharp, tmp);
	}
	else if (c == 'X' && nb != 0)
	{
		sharp = ft_strdup("0X");
		tmp = ft_dup_join(sharp, tmp);
	}
	return (tmp);
}

int		ft_affichex(char c, unsigned long long nb, t_flags *flags)
{
	int		res;
	char	*tmp;

	if (c == 'x' || c == 'p')
		tmp = ft_llbtoa(nb, "0123456789abcdef");
	else
		tmp = ft_llbtoa(nb, "0123456789ABCDEF");
	if (flags->pre > (int)ft_strlen(tmp))
		tmp = ft_prenum(tmp, flags->pre - ft_strlen(tmp));
	if (flags->pre == 0 && nb == 0)
	{
		free(tmp);
		tmp = ft_strdup("");
	}
	if (flags->sharp)
		tmp = ft_sharpx(c, nb, tmp);
	if (flags->size > (int)ft_strlen(tmp))
		tmp = ft_padx(tmp, flags);
	ft_putstr_fd(tmp, flags->fd);
	res = ft_strlen(tmp);
	free(tmp);
	return (res);
}
