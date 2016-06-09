/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pytha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 17:06:28 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/02/02 17:06:30 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free_square(t_coord **carre)
{
	int		i;

	i = -1;
	while (++i < 4)
		free(carre[i]);
	free(carre);
}

t_coord	**ft_trans_hor(t_coord **oldcarre)
{
	t_coord		**newcarre;
	t_coord		*vect;
	int			i;

	newcarre = (t_coord**)malloc(sizeof(t_coord*) * 4);
	vect = (t_coord*)malloc(sizeof(t_coord));
	i = -1;
	while (++i < 4)
		newcarre[i] = (t_coord*)malloc(sizeof(t_coord));
	vect->x = oldcarre[1]->x - oldcarre[3]->x;
	vect->y = oldcarre[1]->y - oldcarre[3]->y;
	newcarre[0]->x = oldcarre[0]->x + vect->x;
	newcarre[0]->y = oldcarre[0]->y + vect->y;
	vect->x = (oldcarre[1]->x - oldcarre[3]->x) / 2;
	vect->y = (oldcarre[1]->y - oldcarre[3]->y) / 2;
	newcarre[1]->x = oldcarre[1]->x + vect->x;
	newcarre[1]->y = oldcarre[1]->y + vect->y;
	newcarre[3]->x = oldcarre[0]->x + vect->x;
	newcarre[3]->y = oldcarre[0]->y + vect->y;
	newcarre[2]->x = oldcarre[1]->x;
	newcarre[2]->y = oldcarre[1]->y;
	free(vect);
	return (newcarre);
}

t_coord	**ft_trans_ahor(t_coord **oldcarre)
{
	t_coord		**newcarre;
	t_coord		*vect;
	int			i;

	newcarre = (t_coord**)malloc(sizeof(t_coord*) * 4);
	vect = (t_coord*)malloc(sizeof(t_coord));
	i = -1;
	while (++i < 4)
		newcarre[i] = (t_coord*)malloc(sizeof(t_coord));
	vect->x = (oldcarre[0]->x - oldcarre[2]->x) / 2;
	vect->y = (oldcarre[0]->y - oldcarre[2]->y) / 2;
	newcarre[0]->x = oldcarre[0]->x + vect->x;
	newcarre[0]->y = oldcarre[0]->y + vect->y;
	newcarre[2]->x = oldcarre[1]->x + vect->x;
	newcarre[2]->y = oldcarre[1]->y + vect->y;
	vect->x = oldcarre[0]->x - oldcarre[2]->x;
	vect->y = oldcarre[0]->y - oldcarre[2]->y;
	newcarre[1]->x = oldcarre[1]->x + vect->x;
	newcarre[1]->y = oldcarre[1]->y + vect->y;
	newcarre[3]->x = oldcarre[0]->x;
	newcarre[3]->y = oldcarre[0]->y;
	free(vect);
	return (newcarre);
}

void	ft_draw_pytha(t_coord **oldcarre, t_env *env, int i)
{
	int		color;
	t_coord	**newcarre;

	if (i >= env->iter)
		return ;
	else
	{
		color = 0;
		if (i % 3 == 0 || i % 3 == 1)
			color += 256 * 256 * 255;
		if (i % 3 == 0 || i % 3 == 2)
			color += 256 * 255;
		if (i % 3 == 1 || i % 3 == 2)
			color += 255;
		newcarre = ft_trans_hor(oldcarre);
		ft_draw_pytha(newcarre, env, i + 1);
		ft_free_square(newcarre);
		newcarre = ft_trans_ahor(oldcarre);
		ft_draw_pytha(newcarre, env, i + 1);
		ft_free_square(newcarre);
		if (i % 2 == 1)
			ft_draw_diamond(oldcarre, color, env);
		if (i % 2 == 0)
			ft_draw_square(oldcarre, color, env);
	}
}

int		ft_expose_pytha(t_env *env)
{
	int		i;
	t_coord **carre;

	carre = (t_coord**)malloc(sizeof(t_coord*) * 4);
	i = -1;
	while (++i < 4)
		carre[i] = (t_coord*)malloc(sizeof(t_coord));
	carre[0]->x = ((WIDTH - 88) / 2) * env->zoom - env->movex;
	carre[0]->y = (HEIGHT - 89) * env->zoom - env->movey;
	carre[1]->x = ((WIDTH + 88) / 2) * env->zoom - env->movex;
	carre[1]->y = (HEIGHT - 89) * env->zoom - env->movey;
	carre[2]->x = ((WIDTH + 88) / 2) * env->zoom - env->movex;
	carre[2]->y = (HEIGHT - 1) * env->zoom - env->movey;
	carre[3]->x = ((WIDTH - 88) / 2) * env->zoom - env->movex;
	carre[3]->y = (HEIGHT - 1) * env->zoom - env->movey;
	ft_draw_pytha(carre, env, 0);
	i = -1;
	while (++i < 4)
		free(carre[i]);
	free(carre);
	i = -1;
	while (++i < 6)
		if (env->move[i])
			ft_move(env);
	return (0);
}
