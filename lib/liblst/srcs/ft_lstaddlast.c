/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 10:00:37 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/21 10:30:06 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list	*list;

	list = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
