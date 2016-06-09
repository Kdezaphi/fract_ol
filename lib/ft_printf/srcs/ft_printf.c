/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 14:50:44 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/10/14 12:05:39 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_backslash(char c)
{
	char	*escape;

	escape = ft_strdup("abfnrtv01234567");
	if ((ft_strchr(escape, c)))
		c = ft_charescape(c);
	write(1, &c, 1);
	free(escape);
}

int		ft_percent(const char *str, int *res, va_list *ap)
{
	int		i;
	char	*str_flags;
	char	*str_type;
	t_flags	*flags;

	i = 0;
	str_flags = ft_strdup("#0-+*. hljz1234567890");
	str_type = ft_strdup("sSpdDioOuUxXcC");
	flags = ft_initflags();
	while (!ft_strchr(str_type, str[i]) && ft_strchr(str_flags, str[i]))
	{
		if (ft_strchr(str_flags, str[i]))
			i += ft_flags(&str[i], flags, ap);
		i++;
	}
	if ((ft_strchr(str_type, str[i])) && str[i])
		ft_type(str[i], res, flags, ap);
	else if (str[i])
		*res += ft_notype(str[i], flags);
	free(str_flags);
	free(str_type);
	free(flags->mod);
	free(flags);
	return (++i);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	int		res;

	i = -1;
	res = 0;
	va_start(ap, str);
	while (++i < (int)ft_strlen(str))
	{
		if (str[i] == '%')
			i += ft_percent(&str[i + 1], &res, &ap);
		else if (str[i] == '\\')
		{
			ft_backslash(str[i + 1]);
			res++;
		}
		else
		{
			write(1, &str[i], 1);
			res++;
		}
	}
	va_end(ap);
	return (res);
}
