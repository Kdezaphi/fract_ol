/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 11:04:50 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/24 16:41:31 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# include "libft.h"
# include "liblst.h"

typedef struct	s_flags
{
	int		sharp;
	int		zero;
	int		neg;
	int		space;
	int		pos;
	int		size;
	int		pre;
	int		fd;
	char	*mod;
}				t_flags;

typedef union	u_dbl
{
	unsigned long	u;
	double			d;
}				t_dbl;

int				ft_printf(const char *str, ...);
size_t			ft_nbblen(unsigned long long n, size_t base);
char			*ft_llbtoa(unsigned long long n, char *base);
char			*ft_lltoa(long long n);
char			ft_charescapedigit(char c);
char			ft_charescape(char c);
void			ft_backslash(char c);
t_flags			*ft_initflags(void);
int				ft_modifier(const char *str, t_flags *flags);
int				ft_setflag(char c, t_flags *flags);
int				ft_setpre(t_flags *flags, char c, va_list *ap);
int				ft_flags(const char *str, t_flags *flags, va_list *ap);
void			ft_padnotype(t_flags *flags);
int				ft_notype(char c, t_flags *flags);
char			*ft_prenum(char *str, int diff);
char			*ft_paddneg(char *tmp, t_flags *flags);
char			*ft_paddposflag(char *tmp, t_flags *flags);
char			*ft_paddpos(char *tmp, t_flags *flags);
int				ft_affichedneg(long long nb, t_flags *flags);
int				ft_affiched(long long nb, t_flags *flags);
int				ft_typed(t_flags *flags, va_list *ap);
int				ft_afficheo(unsigned long long nb, t_flags *flags);
int				ft_typeo(t_flags *flags, va_list *ap);
int				ft_paduzero(t_flags *flags);
int				ft_afficheu(unsigned long long nb, t_flags *flags);
int				ft_typeu(t_flags *flags, va_list *ap);
char			*ft_convpad(char *tmp, char *pad);
char			*ft_padxsharp(char *tmp, t_flags *flags);
char			*ft_padx(char *tmp, t_flags *flags);
int				ft_affichex(char c, unsigned long long nb, t_flags *flags);
int				ft_typex(char c, t_flags *flags, va_list *ap);
int				ft_typenumeric(char c, t_flags *flags, va_list *ap);
int				ft_typep(t_flags *flags, va_list *ap);
char			*ft_paddingchar(t_flags *flags);
int				ft_btoi(char *bin);
int				ft_padczero(t_flags *flags);
int				ft_affichec(char c, t_flags *flags);
int				ft_bin7toint(char *bin, int *cw);
int				ft_bin12toint(char *bin, int *cw);
int				ft_bin17toint(char *bin, int *cw);
int				ft_bin21toint(char *bin, int *cw);
int				ft_wctobin(wint_t cw, int *tabchar);
int				ft_padcw(int *tabchar, int res, t_flags *flags);
int				ft_affichewc(wint_t cw, t_flags *flags);
int				ft_typec(t_flags *flags, va_list *ap);
char			*ft_paddingstr(char *tmp, t_flags *flags);
int				ft_affiches(char *str, t_flags *flags);
int				ft_conswstr(wchar_t *strw, t_list **blist);
int				ft_calclenstrw(t_list **blist, t_flags *flags);
void			ft_printlist(int len, t_list **blist, int fd);
int				ft_padws(int len, t_flags *flags, t_list **blist);
int				ft_affichews(wchar_t *strw, t_flags *flags);
int				ft_types(t_flags *flags, va_list *ap);
int				ft_typestr(char c, t_flags *flags, va_list *ap);
void			ft_type(char c, int *res, t_flags *flags, va_list *ap);
int				ft_percent(const char *str, int *res, va_list *ap);
void			ft_dbackslash(char c, int fd);
int				ft_dpercent(const char *str, int *res, va_list *ap, int fd);
int				ft_dprintf(int fd, const char *str, ...);
void			ft_casezero(char *tmp, int sharp);
char			*ft_sharpx(char c, unsigned long long nb, char *tmp);
char			*ft_pos_space_flag(char *tmp, int pos, int space);
double			ft_sqrt(double d);

#endif
