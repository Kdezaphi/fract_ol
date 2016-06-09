/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdblnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:39:33 by kdezaphi          #+#    #+#             */
/*   Updated: 2014/11/27 17:56:14 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_list_dbl		*ft_lstdblnew(void const *content, size_t content_size)
{
	t_list_dbl	*lstdblnew;

	lstdblnew = (t_list_dbl *)malloc(sizeof(t_list_dbl));
	if (lstdblnew)
	{
		if (content)
		{
			lstdblnew->content = malloc(content_size);
			lstdblnew->content = ft_memcpy(lstdblnew->content,
				content, content_size);
			lstdblnew->content_size = content_size;
		}
		else
		{
			lstdblnew->content = NULL;
			lstdblnew->content_size = 0;
		}
		lstdblnew->next = NULL;
		lstdblnew->prev = NULL;
	}
	return (lstdblnew);
}
