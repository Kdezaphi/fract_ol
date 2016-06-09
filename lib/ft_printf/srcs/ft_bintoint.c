/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:10:39 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 11:19:37 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_btoi(char *bin)
{
	int		i;
	int		res;
	int		nb;

	res = 0;
	i = 0;
	nb = 128;
	while (i < 8)
	{
		res += (bin[i++] - '0') * nb;
		nb /= 2;
	}
	return (res);
}

int		ft_bin7toint(char *bin, int *cw)
{
	int		i;
	int		j;
	char	*tab;

	tab = ft_strdup("00000000");
	i = 0;
	j = 7;
	while (bin[i])
		tab[j--] = bin[i++];
	i = -1;
	while (++i < 1)
		cw[i] = ft_btoi(&tab[i * 8]);
	cw[i] = 0;
	free(tab);
	return (1);
}

int		ft_bin12toint(char *bin, int *cw)
{
	int		i;
	int		j;
	char	*tab;

	tab = ft_strdup("1100000010000000");
	i = 0;
	j = 15;
	while (bin[i])
	{
		tab[j--] = bin[i++];
		if (j == 9)
			j = 7;
	}
	i = -1;
	while (++i < 2)
		cw[i] = ft_btoi(&tab[i * 8]);
	cw[i] = 0;
	free(tab);
	return (2);
}

int		ft_bin17toint(char *bin, int *cw)
{
	int		i;
	int		j;
	char	*tab;

	tab = ft_strdup("111000001000000010000000");
	i = 0;
	j = 23;
	while (bin[i])
	{
		tab[j--] = bin[i++];
		if (j == 9 || j == 17)
			j -= 2;
	}
	i = -1;
	while (++i < 3)
		cw[i] = ft_btoi(&tab[i * 8]);
	cw[i] = 0;
	free(tab);
	return (3);
}

int		ft_bin21toint(char *bin, int *cw)
{
	int		i;
	int		j;
	char	*tab;

	tab = ft_strdup("11110000100000001000000010000000");
	i = 0;
	j = 31;
	while (bin[i])
	{
		tab[j--] = bin[i++];
		if (j == 9 || j == 17 || j == 25)
			j -= 2;
	}
	i = -1;
	while (++i < 4)
		cw[i] = ft_btoi(&tab[i * 8]);
	cw[i] = 0;
	free(tab);
	return (4);
}
