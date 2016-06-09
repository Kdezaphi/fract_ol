/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mandel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 17:01:02 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/12/01 18:14:03 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_set_color(int i, t_env *env)
{
	int		color;

	color = 0;
	if (i == env->iter)
		return (0xffffff);
	i %= 360;
	if (i < 60)
		color = 256 * 256 * 255 + 256 * (255 / 60 * (i % 60 + 1));
	else if (i < 120)
		color = 256 * 256 * (255 / 60 * (i % 60 + 1)) + 256 * 255;
	else if (i < 180)
		color = 256 * 255 + (255 / 60 * (i % 60 + 1));
	else if (i < 240)
		color = 256 * (255 / 60 * (i % 60 + 1)) + 255;
	else if (i < 300)
		color = 256 * 256 * (255 / 60 * (i % 60 + 1)) + 255;
	else
		color = 256 * 256 * 255 + (255 / 60 * (i % 60 + 1));
	return (color);
}

int		ft_iter_julia(t_coord *new, t_coord *old, t_env *env)
{
	int		i;

	i = -1;
	while (++i < env->iter)
	{
		old->x = new->x;
		old->y = new->y;
		new->x = old->x * old->x - old->y * old->y + env->cre;
		new->y = 2 * old->x * old->y + env->cim;
		if (new->x * new->x + new->y * new->y > env->zoom * env->plus)
			break ;
	}
	return (ft_set_color(i, env));
}

void	ft_expose_julia(t_env *env)
{
	t_coord	new;
	t_coord	old;
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			new.x = 1.5 * (x - WIDTH / 2) / (0.5 * env->zoom * WIDTH) +
				env->movex;
			new.y = (y - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + env->movey;
			ft_pixel_to_image(x, y, env, ft_iter_julia(&new, &old, env));
		}
	}
	x = -1;
	while (++x < 6)
		if (env->move[x])
			ft_move(env);
}

int		ft_iter_mandel(t_coord *new, t_coord *old, t_coord *nbr, t_env *env)
{
	int		i;

	i = 0;
	while (i < env->iter)
	{
		old->x = new->x;
		old->y = new->y;
		new->x = old->x * old->x - old->y * old->y + nbr->x;
		new->y = 2 * old->x * old->y + nbr->y;
		if (new->x * new->x + new->y * new->y > env->zoom * env->plus)
			break ;
		i++;
	}
	return (ft_set_color(i, env));
}

void	ft_expose_mandel(t_env *env)
{
	t_coord	new;
	t_coord	old;
	t_coord nbr;
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			nbr.x = 1.5 * (x - WIDTH / 2) /
				(0.5 * env->zoom * WIDTH) + env->movex;
			nbr.y = (y - HEIGHT / 2) /
				(0.5 * env->zoom * HEIGHT) + env->movey;
			new.x = env->cre;
			new.y = env->cim;
			ft_pixel_to_image(x, y, env, ft_iter_mandel(&new, &old, &nbr, env));
		}
	}
	x = -1;
	while (++x < 6)
		if (env->move[x])
			ft_move(env);
}
