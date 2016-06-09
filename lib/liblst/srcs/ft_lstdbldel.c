/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbldel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 12:59:04 by kdezaphi          #+#    #+#             */
/*   Updated: 2016/06/09 13:25:13 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	ft_lstdbldel(t_list_def *def, void (*del)(void *))
{
	t_list_dbl	*list;

	list = def->first;
	while (list)
	{
		(*del)(list->content);
		list = def->first->next;
		free(def->first);
		def->first = list;
	}
	def->first = NULL;
	list = NULL;
	free(def);
}
