/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:39:59 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/05 13:02:04 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int	stop;
	char			*str;
	int				i;

	stop = start + (unsigned int)len;
	str = (char *)malloc(len + 1);
	if (str && s)
	{
		i = 0;
		while (start < stop)
			str[i++] = s[start++];
		str[i] = '\0';
	}
	return (str);
}
