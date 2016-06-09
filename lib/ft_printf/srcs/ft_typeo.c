/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:18:17 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 12:34:00 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_casezero(char *tmp, int sharp)
{
	if (sharp)
		tmp[0] = '0';
	else
		tmp[0] = '\0';
	tmp[1] = '\0';
}

int		ft_afficheo(unsigned long long nb, t_flags *flags)
{
	int		res;
	char	*tmp;
	char	*zero;

	tmp = ft_llbtoa(nb, "01234567");
	if (flags->sharp && nb != 0)
	{
		zero = ft_strdup("0");
		tmp = ft_strjoin(zero, tmp);
	}
	if (flags->pre > (int)ft_strlen(tmp))
		tmp = ft_prenum(tmp, flags->pre - ft_strlen(tmp));
	if (flags->pre == 0 && nb == 0)
		ft_casezero(tmp, flags->sharp);
	if (flags->size > (int)ft_strlen(tmp))
	{
		flags->space = 0;
		flags->pos = 0;
		tmp = ft_paddpos(tmp, flags);
	}
	write(flags->fd, tmp, ft_strlen(tmp));
	res = ft_strlen(tmp);
	free(tmp);
	return (res);
}
