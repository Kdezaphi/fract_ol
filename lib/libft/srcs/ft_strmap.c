/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:25:30 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/05 10:25:31 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = -1;
	str = (char *)malloc(sizeof(s) + 1);
	if (str && (*f) && s)
	{
		while (s[++i])
			str[i] = (*f)(s[i]);
		str[i] = '\0';
	}
	return (str);
}
