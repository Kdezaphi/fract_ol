/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 08:48:03 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/05 08:48:05 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;

	sign = 1;
	i = 0;
	res = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (int)(str[i++] - '0');
	return (res * sign);
}
