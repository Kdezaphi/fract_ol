/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:37:52 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/05 10:37:53 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (1);
	else if (s1 && s2)
		return (!ft_strncmp(s1, s2, n));
	return (0);
}
