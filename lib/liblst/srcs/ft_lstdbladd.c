/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbladd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:50:14 by kdezaphi          #+#    #+#             */
/*   Updated: 2016/06/09 13:17:47 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void			ft_lstdbladd(t_list_def *def, t_list_dbl *prev_elem,
	t_list_dbl *new_elem)
{
	t_list_dbl	*next_elem;

	next_elem = prev_elem->next;
	prev_elem->next = new_elem;
	new_elem->prev = prev_elem;
	next_elem->prev = new_elem;
	new_elem->next = next_elem;
	def->nb_elem++;
}
