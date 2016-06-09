/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:38:17 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/12/03 15:10:52 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmpdst;
	char	*tmpsrc;
	char	*tmp;
	size_t	i;

	tmp = (char*)malloc(len);
	tmpdst = (char*)dst;
	tmpsrc = (char*)src;
	i = 0;
	while (i < len)
	{
		tmp[i] = tmpsrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		tmpdst[i] = tmp[i];
		i++;
	}
	return (dst);
}
