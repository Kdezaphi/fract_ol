/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 15:19:31 by kdezaphi          #+#    #+#             */
/*   Updated: 2016/06/09 13:18:18 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLST_H
# define LIBLST_H

# include <stdlib.h>
# include "libft.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_list_dbl
{
	void				*content;
	size_t				content_size;
	struct s_list_dbl	*next;
	struct s_list_dbl	*prev;
}				t_list_dbl;

typedef struct	s_list_def
{
	t_list_dbl	*first;
	t_list_dbl	*last;
	int			nb_elem;
}				t_list_def;

t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstaddlast(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list_dbl		*ft_lstdblnew(void const *content, size_t content_size);
void			ft_lstdbladd(t_list_def *def, t_list_dbl *prev_elem,
	t_list_dbl *new_elem);
void			ft_lstdbladd_first(t_list_def *def, t_list_dbl *new);
void			ft_lstdbladd_last(t_list_def *def, t_list_dbl *new);
t_list_def		*ft_initdef(void);
void			ft_lstdbldel(t_list_def *def, void (*del)(void *));
void			ft_lstdbldelone(t_list_def *def, t_list_dbl *list,
	void (*del)(void *));

#endif
