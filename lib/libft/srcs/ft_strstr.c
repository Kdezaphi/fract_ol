/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:44:55 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/04 15:44:57 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = -1;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + 1;
		while (++i < len)
		{
			j = 0;
			while (s1[i + j] == s2[j] && s1[i + j] && s2[j])
				j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
	}
	return ((char *)NULL);
}
