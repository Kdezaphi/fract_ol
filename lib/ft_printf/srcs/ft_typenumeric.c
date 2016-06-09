/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typenumeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:19:51 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 11:22:04 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_typed(t_flags *flags, va_list *ap)
{
	long long	nb;

	nb = 0;
	if (!ft_strcmp(flags->mod, "ll") || flags->mod[0] == 'z')
		nb = va_arg(*ap, long long);
	else if (flags->mod[0] == 'l' || flags->mod[0] == '0')
		nb = (long)va_arg(*ap, long);
	else if (flags->mod[0] == 0)
		nb = (int)va_arg(*ap, int);
	else if (!ft_strcmp(flags->mod, "hh"))
		nb = (char)va_arg(*ap, int);
	else if (flags->mod[0] == 'h')
		nb = (short)va_arg(*ap, int);
	else if (flags->mod[0] == 'j')
		nb = (intmax_t)va_arg(*ap, intmax_t);
	return (ft_affiched(nb, flags));
}

int		ft_typeo(t_flags *flags, va_list *ap)
{
	unsigned long long	nb;

	nb = 0;
	if (!ft_strcmp(flags->mod, "ll"))
		nb = va_arg(*ap, unsigned long long);
	else if (flags->mod[0] == 'l' || flags->mod[0] == '0')
		nb = (unsigned long)va_arg(*ap, unsigned long);
	else if (flags->mod[0] == 0)
		nb = (unsigned int)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(flags->mod, "hh"))
		nb = (unsigned char)va_arg(*ap, unsigned int);
	else if (flags->mod[0] == 'h')
		nb = (unsigned short)va_arg(*ap, unsigned int);
	else if (flags->mod[0] == 'j')
		nb = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (flags->mod[0] == 'z')
		nb = (size_t)va_arg(*ap, size_t);
	return (ft_afficheo(nb, flags));
}

int		ft_typeu(t_flags *flags, va_list *ap)
{
	unsigned long long	nb;

	nb = 0;
	if (!ft_strcmp(flags->mod, "ll"))
		nb = va_arg(*ap, unsigned long long);
	else if (flags->mod[0] == 'l' || flags->mod[0] == '0')
		nb = (unsigned long)va_arg(*ap, unsigned long);
	else if (flags->mod[0] == 0)
		nb = (unsigned int)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(flags->mod, "hh"))
		nb = (unsigned char)va_arg(*ap, unsigned int);
	else if (flags->mod[0] == 'h')
		nb = (unsigned short)va_arg(*ap, unsigned int);
	else if (flags->mod[0] == 'j')
		nb = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (flags->mod[0] == 'z')
		nb = (size_t)va_arg(*ap, size_t);
	return (ft_afficheu(nb, flags));
}

int		ft_typex(char c, t_flags *flags, va_list *ap)
{
	unsigned long long	nb;

	nb = 0;
	if (!ft_strcmp(flags->mod, "ll"))
		nb = va_arg(*ap, unsigned long long);
	else if (flags->mod[0] == 'l' || flags->mod[0] == '0')
		nb = (unsigned long)va_arg(*ap, unsigned long);
	else if (flags->mod[0] == 0)
		nb = (unsigned int)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(flags->mod, "hh"))
		nb = (unsigned char)va_arg(*ap, unsigned int);
	else if (flags->mod[0] == 'h')
		nb = (unsigned short)va_arg(*ap, unsigned int);
	else if (flags->mod[0] == 'j')
		nb = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (flags->mod[0] == 'z')
		nb = (size_t)va_arg(*ap, size_t);
	return (ft_affichex(c, nb, flags));
}

int		ft_typep(t_flags *flags, va_list *ap)
{
	unsigned long long nb;

	nb = (unsigned long)va_arg(*ap, unsigned long);
	flags->sharp = 1;
	return (ft_affichex('p', nb, flags));
}
