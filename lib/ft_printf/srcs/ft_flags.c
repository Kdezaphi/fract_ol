/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:22:39 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 11:19:51 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_initflags(void)
{
	t_flags	*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->sharp = 0;
	flags->zero = 0;
	flags->neg = 0;
	flags->space = 0;
	flags->pos = 0;
	flags->size = 0;
	flags->pre = -1;
	flags->fd = 1;
	flags->mod = ft_strdup("");
	return (flags);
}

int		ft_modifier(const char *str, t_flags *flags)
{
	if (!flags->mod[0])
	{
		free(flags->mod);
		if ((str[0] == 'h' || str[0] == 'l') && str[0] == str[1])
		{
			flags->mod = (char*)malloc(3);
			flags->mod[0] = str[0];
			flags->mod[1] = str[1];
			flags->mod[2] = '\0';
			return (1);
		}
		else
		{
			flags->mod = (char*)malloc(2);
			flags->mod[0] = str[0];
			flags->mod[1] = '\0';
		}
	}
	else
	{
		free(flags->mod);
		flags->mod = ft_strdup("0");
	}
	return (0);
}

int		ft_setflag(char c, t_flags *flags)
{
	if (c == '#')
		flags->sharp = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '-')
		flags->neg = 1;
	else if (c == '+')
		flags->pos = 1;
	else if (c == ' ')
		flags->space = 1;
	return (0);
}

int		ft_setpre(t_flags *flags, char c, va_list *ap)
{
	if (c == '*')
	{
		flags->pre = va_arg(*ap, int);
		if (flags->pre < 0)
			flags->pre = -1;
		return (1);
	}
	flags->pre = 0;
	return (0);
}

int		ft_flags(const char *str, t_flags *flags, va_list *ap)
{
	if ((ft_strchr("hljz", str[0])))
		return (ft_modifier(&str[0], flags));
	else if ((ft_strchr("#0-+ ", str[0])))
		return (ft_setflag(str[0], flags));
	else if ((ft_isdigit(str[0])))
	{
		flags->size = ft_atoi(&str[0]);
		return (ft_nblen((long)flags->size) - 1);
	}
	else if (str[0] == '*')
		flags->size = va_arg(*ap, int);
	else if (str[0] == '.' && (ft_isdigit(str[1])))
	{
		if (ft_atoi(&str[1]) >= 0)
			flags->pre = ft_atoi(&str[1]);
		return (ft_nblen((long)flags->pre));
	}
	else if (str[0] == '.' && !(ft_isdigit(str[1])))
		return (ft_setpre(flags, str[1], ap));
	return (0);
}
