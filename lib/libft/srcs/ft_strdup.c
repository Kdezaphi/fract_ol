/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:30:47 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/04 14:30:49 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	len = -1;
	while (s1[++len] != '\0')
		s2[len] = s1[len];
	s2[len] = '\0';
	return (s2);
}
