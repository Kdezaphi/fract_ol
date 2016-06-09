/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typewc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:09:01 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 12:34:23 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wctobin(wint_t cw, int *tabchar)
{
	int		i;
	char	bin[22];

	i = 0;
	while (cw)
	{
		bin[i++] = (cw & 1) ? '1' : '0';
		cw >>= 1;
	}
	bin[i] = '\0';
	if (i < 8)
		return (ft_bin7toint(bin, tabchar));
	if (i < 12)
		return (ft_bin12toint(bin, tabchar));
	else if (i < 17)
		return (ft_bin17toint(bin, tabchar));
	else if (i < 22)
		return (ft_bin21toint(bin, tabchar));
	return (0);
}

int		ft_padcw(int *tabchar, int res, t_flags *flags)
{
	char	*pad;
	int		i;

	pad = (char*)malloc(flags->size - res + 1);
	i = -1;
	if (flags->zero && !flags->neg)
		while (++i < flags->size - res)
			pad[i] = '0';
	else
		while (++i < flags->size - res)
			pad[i] = ' ';
	pad[i] = '\0';
	if (!flags->neg)
		write(flags->fd, pad, ft_strlen(pad));
	i = 0;
	while (tabchar[i] && i < 4)
		write(1, &tabchar[i++], 1);
	if (flags->neg)
		write(flags->fd, pad, ft_strlen(pad));
	free(pad);
	return (flags->size);
}

int		ft_affichewc(wint_t cw, t_flags *flags)
{
	int		res;
	int		tabchar[5];
	int		i;

	res = ft_wctobin(cw, tabchar);
	if (tabchar[1] == 0)
		return (ft_affichec(tabchar[0], flags));
	if (flags->size > res)
		return (ft_padcw(tabchar, res, flags));
	i = 0;
	while (tabchar[i] && i < 4)
		write(flags->fd, &tabchar[i++], 1);
	return (res);
}
