/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:32:50 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/05 10:32:52 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = -1;
	str = (char *)malloc(sizeof(s) + 1);
	if (s && str && (*f))
	{
		while (s[++i])
			str[i] = (*f)(i, s[i]);
		str[i] = '\0';
	}
	return (str);
}
