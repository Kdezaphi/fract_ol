/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:25:12 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 15:29:39 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_bclnorme(char *res, char **nb, int i, int j)
{
	int		ret;

	ret = 0;
	while (--i >= 0)
	{
		res[i] = nb[0][i];
		if (j >= 0)
			res[i] += nb[1][j--] - '0';
		if (ret)
			res[i] += ret--;
		if (res[i] > '9')
		{
			res[i] = (res[i] - '0') % 10 + '0';
			ret = 1;
		}
	}
	return (ret);
}

static char	*ft_add(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;
	char	*nb[2];

	if (ft_strlen(s1) < ft_strlen(s2))
	{
		nb[0] = ft_strdup(s2);
		nb[1] = ft_strdup(s1);
	}
	else
	{
		nb[0] = ft_strdup(s1);
		nb[1] = ft_strdup(s2);
	}
	i = ft_strlen(nb[0]);
	j = ft_strlen(nb[1]) - 1;
	res = (char*)malloc(ft_strlen(nb[0]) + 1);
	res[ft_strlen(nb[0])] = '\0';
	if (ft_bclnorme(res, nb, i, j))
		res = ft_addret(res, ft_strlen(nb[0]));
	free(nb[0]);
	free(nb[1]);
	return (res);
}

static char	*ft_mult2(char *nb)
{
	char	*res;
	int		i;
	int		ret;
	int		len;

	ret = 0;
	len = ft_strlen(nb);
	i = len;
	res = (char*)malloc(len + 1);
	res[len] = '\0';
	while (--i >= 0)
	{
		res[i] = (nb[i] - '0') * 2 % 10 + '0';
		if (ret)
		{
			res[i]++;
			ret = 0;
		}
		if (nb[i] > '4')
			ret = 1;
	}
	if (ret)
		res = ft_addret(res, len);
	free(nb);
	return (res);
}

static void	ft_setbin_intp(char *s, char *bin, int i, int val)
{
	int		j;

	bin[0] = '1';
	j = 1;
	while (j + 11 <= i && j < val)
	{
		bin[j] = s[j + 11];
		j++;
	}
	while (j < val)
		bin[j++] = '0';
	bin[j] = '\0';
}

char		*ft_intp(char *s, int i, int val)
{
	char	*intp;
	char	*pui;
	char	*bin;
	char	*tmp;

	bin = (char*)malloc(val + 1);
	ft_setbin_intp(s, bin, i, val);
	intp = ft_strdup("0");
	pui = ft_strdup("1");
	i = val - 1;
	while (i >= 0)
	{
		if (bin[i] == '1')
		{
			tmp = ft_strdup(intp);
			free(intp);
			intp = ft_add(tmp, pui);
			free(tmp);
		}
		pui = ft_mult2(pui);
		i--;
	}
	free(bin);
	return (intp);
}
