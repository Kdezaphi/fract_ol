/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typews.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 10:38:51 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/23 12:34:30 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conswstr(wchar_t *strw, t_list **blist)
{
	t_list	*list;
	int		res;
	int		tab[5];

	res = 0;
	while (*strw)
	{
		if ((tab[4] = ft_wctobin(*strw, tab)))
		{
			res += tab[4];
			list = ft_lstnew(tab, sizeof(int) * 5);
			ft_lstaddlast(blist, list);
			strw++;
		}
		else
			return (0);
	}
	return (res);
}

int		ft_calclenstrw(t_list **blist, t_flags *flags)
{
	t_list	*list;
	int		res;
	int		*tab;

	list = *blist;
	res = 0;
	while (list)
	{
		tab = (int*)list->content;
		if (flags->pre == -1 || res + tab[4] <= flags->pre)
			res += tab[4];
		else
			break ;
		list = list->next;
	}
	return (res);
}

void	ft_printlist(int len, t_list **blist, int fd)
{
	int		*tab;
	int		i;
	t_list	*list;

	list = *blist;
	while (len)
	{
		tab = (int*)list->content;
		i = 0;
		while (tab[i] && i < 4)
			write(fd, &tab[i++], 1);
		len -= tab[4];
		if (list->next)
			list = list->next;
	}
	while (*blist)
	{
		list = *blist;
		*blist = list->next;
		free(list->content);
		free(list);
	}
	free(*blist);
}

int		ft_padws(int len, t_flags *flags, t_list **blist)
{
	char	*pad;
	int		lenpad;
	int		i;

	lenpad = flags->size - len;
	pad = (char*)malloc(lenpad + 1);
	i = -1;
	if (flags->zero && !flags->neg)
		while (++i < lenpad)
			pad[i] = '0';
	else
		while (++i < lenpad)
			pad[i] = ' ';
	pad[i] = '\0';
	if (!flags->neg)
		write(flags->fd, pad, ft_strlen(pad));
	ft_printlist(len, blist, flags->fd);
	if (flags->neg)
		write(flags->fd, pad, ft_strlen(pad));
	free(pad);
	return (flags->size);
}

int		ft_affichews(wchar_t *strw, t_flags *flags)
{
	t_list	*liststrw;
	int		len;

	liststrw = NULL;
	if (!strw)
		return (ft_affiches(NULL, flags));
	if (ft_conswstr(strw, &liststrw))
	{
		len = ft_calclenstrw(&liststrw, flags);
		if (len < flags->size)
			return (ft_padws(len, flags, &liststrw));
		ft_printlist(len, &liststrw, flags->fd);
		return (len);
	}
	return (0);
}
