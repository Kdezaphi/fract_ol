/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:45:53 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/04 13:45:54 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tmps;
	size_t	i;

	i = -1;
	tmps = (char *)s;
	while (++i < n)
		if (tmps[i] == (char)c)
			return ((void *)&tmps[i]);
	return (NULL);
}
