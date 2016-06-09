/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:09:44 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/02/13 16:34:16 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	int		stop;
	char	*str;

	i = 0;
	str = NULL;
	if (s)
	{
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
			i++;
		stop = (int)ft_strlen(s) - 1;
		while ((s[stop] == ' ' || s[stop] == '\t' || s[stop] == '\n') && s[i])
			stop--;
		str = (char *)malloc(stop - i + 2);
		if (str)
		{
			j = 0;
			while (i <= stop)
				str[j++] = s[i++];
			str[j] = '\0';
		}
	}
	return (str);
}
