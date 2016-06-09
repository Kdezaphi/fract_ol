/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initdef.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 12:56:32 by kdezaphi          #+#    #+#             */
/*   Updated: 2016/06/09 12:58:01 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_list_def	*ft_initdef(void)
{
	t_list_def	*def;

	def = (t_list_def*)malloc(sizeof(t_list_def));
	def->first = NULL;
	def->last = NULL;
	def->nb_elem = 0;
	return (def);
}
