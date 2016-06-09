/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:37:24 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/12/01 13:23:24 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	len = ft_nblen((long long)n);
	str = (char *)malloc(len + 1);
	if (n < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (n != 0)
	{
		str[len--] = n % 10 * sign + '0';
		n /= 10;
	}
	return (str);
}
