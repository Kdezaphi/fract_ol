/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:23:48 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 15:29:32 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_div2(char *dec, int i)
{
	int		j;
	int		ret;

	j = 0;
	ret = 0;
	while (j < i + 2)
	{
		if (ret)
			dec[j] += 10;
		ret = (dec[j] - '0') % 2;
		dec[j] = (dec[j] - '0') / 2 + '0';
		j++;
	}
}

static char	*ft_setbin_dec(char *s, int i, int val, char sub)
{
	int		j;
	char	*bin;

	bin = (char*)malloc(val + 1);
	j = 0;
	while (j < val && i > 11)
		bin[j++] = s[i--];
	if (j < val)
	{
		bin[j++] = sub;
		while (j < val)
			bin[j++] = '0';
	}
	bin[j] = '\0';
	return (bin);
}

char		*ft_dec(char *s, int i, int val, char sub)
{
	char	*dec;
	char	*bin;

	bin = ft_setbin_dec(s, i, val, sub);
	dec = (char*)malloc(val + 2);
	dec[val + 1] = '\0';
	ft_memset(dec, '0', val + 1);
	i = 0;
	while (i < val)
	{
		if (bin[i] == '1')
			dec[0] = '1';
		ft_div2(dec, i);
		i++;
	}
	dec[0] = '.';
	free(bin);
	return (dec);
}
