/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbladd_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:50:30 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/27 17:55:46 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	ft_lstdbladd_first(t_list_def *def, t_list_dbl *new)
{
	t_list_dbl	*list;

	if (new)
	{
		if (!(def->last))
		{
			def->last = new;
			def->first = new;
		}
		else
		{
			list = def->first;
			def->first = new;
			new->next = list;
			list->prev = new;
		}
		def->nb_elem++;
	}
}
