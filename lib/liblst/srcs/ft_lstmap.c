/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:05:21 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/02/13 16:35:07 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_list;
	t_list	*list;
	t_list	*new;

	begin_list = NULL;
	list = (t_list *)malloc(sizeof(t_list));
	if (list && (*f) && lst)
	{
		list = (*f)(lst);
		begin_list = list;
		while (lst->next)
		{
			lst = lst->next;
			new = (t_list *)malloc(sizeof(t_list));
			if (new)
			{
				new = (*f)(lst);
				list->next = new;
				list = list->next;
			}
			else
				return (NULL);
		}
	}
	return (begin_list);
}
