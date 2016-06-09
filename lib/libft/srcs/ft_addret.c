/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:42:57 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/24 16:43:16 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addret(char *nb, int len)
{
	int		i;
	char	*res;

	res = (char*)malloc(len + 2);
	res[0] = '1';
	i = 1;
	while (i - 1 < len)
	{
		res[i] = nb[i - 1];
		i++;
	}
	res[i] = '\0';
	free(nb);
	return (res);
}
