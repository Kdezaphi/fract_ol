/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:58:54 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/06 15:58:58 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *list;

	list = lst;
	while (list != NULL)
	{
		(*f)(list);
		list = list->next;
	}
}
