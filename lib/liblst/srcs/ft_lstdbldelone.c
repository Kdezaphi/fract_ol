/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbldelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 13:06:45 by kdezaphi          #+#    #+#             */
/*   Updated: 2016/06/09 13:15:04 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	ft_lstdbldelone(t_list_def *def, t_list_dbl *list, void (*del)(void *))
{
	t_list_dbl	*prev;

	if (!list->prev)
		def->first = list->next;
	else
	{
		prev = list->prev;
		prev->next = list->next;
	}
	if (!list->next)
		def->last = list->prev;
	else
		list->next->prev = prev;
	(*del)(list->content);
	free(list);
	def->nb_elem--;
}
