/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:27:54 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/24 16:41:08 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_notype(char c, t_flags *flags)
{
	if (flags->size)
	{
		if (flags->size < 0)
		{
			flags->size *= -1;
			flags->neg = 1;
		}
		if (flags->neg)
		{
			write(flags->fd, &c, 1);
			ft_padnotype(flags);
		}
		else
		{
			ft_padnotype(flags);
			write(flags->fd, &c, 1);
		}
		return (flags->size);
	}
	write(flags->fd, &c, 1);
	return (1);
}

int		ft_typenumeric(char c, t_flags *flags, va_list *ap)
{
	if (ft_isupper(c) && c != 'X')
	{
		c = ft_tolower(c);
		free(flags->mod);
		flags->mod = ft_strdup("l");
	}
	if (c == 'd' || c == 'i')
		return (ft_typed(flags, ap));
	else if (c == 'o')
		return (ft_typeo(flags, ap));
	else if (c == 'u')
		return (ft_typeu(flags, ap));
	else if (c == 'x' || c == 'X')
		return (ft_typex(c, flags, ap));
	return (0);
}

int		ft_typestr(char c, t_flags *flags, va_list *ap)
{
	if (ft_isupper(c))
	{
		free(flags->mod);
		flags->mod = ft_strdup("l");
		c = ft_tolower(c);
	}
	if (c == 'c')
		return (ft_typec(flags, ap));
	else if (c == 's')
		return (ft_types(flags, ap));
	return (0);
}

void	ft_type(char c, int *res, t_flags *flags, va_list *ap)
{
	char	*numeric;
	char	*str;

	numeric = ft_strdup("dDioOuUxX");
	str = ft_strdup("sScC");
	if (flags->size < 0)
	{
		flags->size *= -1;
		flags->neg = 1;
	}
	if ((ft_strchr(numeric, c)))
		*res += ft_typenumeric(c, flags, ap);
	else if ((ft_strchr(str, c)))
		*res += ft_typestr(c, flags, ap);
	else if (c == 'p')
		*res += ft_typep(flags, ap);
	free(numeric);
	free(str);
}
