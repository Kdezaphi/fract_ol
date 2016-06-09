/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 13:15:00 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/12/01 13:15:01 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_nblen(long long n)
{
	size_t	nb_char;

	nb_char = 0;
	if (n < 0)
		nb_char++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		nb_char++;
		n /= 10;
	}
	return (nb_char);
}
