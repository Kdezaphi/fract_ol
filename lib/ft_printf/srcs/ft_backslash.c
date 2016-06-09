/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backslash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:23:58 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 11:19:29 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_charescapedigit(char c)
{
	if (c == '0')
		return ('\0');
	else if (c == '1')
		return ('\1');
	else if (c == '2')
		return ('\2');
	else if (c == '3')
		return ('\3');
	else if (c == '4')
		return ('\4');
	else if (c == '5')
		return ('\5');
	else if (c == '6')
		return ('\6');
	else if (c == '7')
		return ('\7');
	return (0);
}

char	ft_charescape(char c)
{
	if (ft_isdigit(c))
		return (ft_charescapedigit(c));
	else if (c == '\'')
		return ('\'');
	else if (c == '\"')
		return ('\"');
	else if (c == 'a')
		return ('\a');
	else if (c == 'b')
		return ('\b');
	else if (c == 'a')
		return ('\f');
	else if (c == 'f')
		return ('\n');
	else if (c == 'n')
		return ('\n');
	else if (c == 'r')
		return ('\r');
	else if (c == 't')
		return ('\t');
	else if (c == 'v')
		return ('\v');
	return (0);
}
