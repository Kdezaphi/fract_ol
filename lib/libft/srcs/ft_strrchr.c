/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:38:44 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/04 15:38:45 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(s) + 1;
	while (++i < len)
		if (s[len - i - 1] == (char)c)
			return ((char *)&s[len - i - 1]);
	return ((char *)NULL);
}
