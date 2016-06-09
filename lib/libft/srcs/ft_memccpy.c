/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:22:18 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/04 13:22:21 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*tmpdst;
	char	*tmpsrc;
	size_t	i;

	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	i = -1;
	while (++i < n)
	{
		tmpdst[i] = tmpsrc[i];
		if (tmpsrc[i] == (unsigned char)c)
			break ;
	}
	if (i == n)
		return (NULL);
	return ((void *)&tmpdst[++i]);
}
