/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:14:36 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/04 15:14:38 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	if (i <= size)
		len = ft_strlen(dst) + ft_strlen(src);
	else
		len = size + ft_strlen(src);
	if (i < size)
	{
		j = 0;
		while (src[j] && i < size - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (len);
}
