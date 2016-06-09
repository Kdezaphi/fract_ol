/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:25:43 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/02/04 12:47:55 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmpdst;
	const char	*tmpsrc;
	size_t		i;

	i = -1;
	tmpsrc = (const char *)src;
	tmpdst = (char *)dst;
	while (++i < n)
		tmpdst[i] = tmpsrc[i];
	return (dst);
}
