/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:45:38 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/04 11:45:56 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*tmp;

	i = -1;
	tmp = (char *)b;
	while (++i < len)
		tmp[i] = (unsigned char)c;
	return (b);
}
