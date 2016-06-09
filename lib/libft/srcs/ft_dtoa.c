/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:19:04 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/24 16:44:17 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned short	ft_calc_e(char *bin)
{
	unsigned short	e;
	unsigned int	m;
	int				i;

	i = 1;
	m = 1;
	e = 0;
	while (i < 12)
	{
		e += (bin[12 - i] - '0') * m;
		m *= 2;
		i++;
	}
	return (e);
}

static void				ft_dtob(double d, char *s)
{
	t_dbl	nb;
	int		i;

	nb.d = d;
	s[64] = '\0';
	i = 63;
	while (i >= 0)
	{
		s[i] = (nb.u & 1) + '0';
		nb.u >>= 1;
		i--;
	}
}

static char				*ft_setsign(char *intp, char *dec, int sign)
{
	char	*res;
	char	*tmp;

	if (sign == '1')
	{
		tmp = ft_strjoin("-", intp);
		res = ft_strjoin(tmp, dec);
		free(tmp);
	}
	else
		res = ft_strjoin(intp, dec);
	free(intp);
	free(dec);
	return (res);
}

static char				*ft_spec_exp(char *s, unsigned short e, int i)
{
	char	*res;

	if (e == 2047)
	{
		if (i > 12 || s[12] == '1')
			res = ft_strdup("nan");
		else
			res = ft_setsign(ft_strdup("inf"), ft_strdup(""), s[0]);
	}
	else
	{
		if (i > 12 || s[12] == '1')
			res = ft_setsign(ft_strdup("0"), ft_dec(s, i, i + 1011, '0'), s[0]);
		else
			res = ft_setsign(ft_strdup("0"), ft_strdup(""), s[0]);
	}
	return (res);
}

char					*ft_dtoa(double d)
{
	int				i;
	char			s[65];
	char			*dec;
	char			*intp;
	unsigned short	e;

	ft_dtob(d, s);
	e = ft_calc_e(s);
	i = 63;
	while (s[i] == '0' && i > 12)
		i--;
	if (e == 2047 || e == 0)
		return (ft_spec_exp(s, e, i));
	else
	{
		if (i - e + 1012 > 0)
			dec = ft_dec(s, i, i - e + 1012, '1');
		else
			dec = ft_strdup(".0");
		if (e - 1022 > 0)
			intp = ft_intp(s, i, e - 1022);
		else
			intp = ft_strdup("0");
		return (ft_setsign(intp, dec, s[0]));
	}
}
