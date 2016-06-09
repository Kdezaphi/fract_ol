/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 08:52:55 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/02/04 08:52:57 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_set_color_newton(t_coord *new)
{
	int		color;

	color = 0;
	if (new->x == -1. && new->y == 0.)
		color = 255;
	else if (new->x == 0.5)
	{
		if (new->y > 0)
			color = 256 * 255;
		else
			color = 256 * 256 * 255;
	}
	return (color);
}

int		ft_iter_newton(t_coord *new, t_coord *old, t_env *env)
{
	int		i;
	double	divi;
	double	resre;
	double	resim;

	i = -1;
	while (++i < env->iter / 8 + 64)
	{
		old->x = new->x;
		old->y = new->y;
		divi = 3. * (old->x * old->x * old->x * old->x + 2. * old->x * old->x *
			old->y * old->y + old->y * old->y * old->y * old->y);
		new->x = (2. * old->x * old->x * old->x * old->x * old->x + 4. *
			old->x * old->x * old->x * old->y * old->y + 2. * old->x * old->y *
			old->y * old->y * old->y - old->x * old->x + old->y * old->y) /
			divi;
		new->y = (2. * (old->x * old->x * old->x * old->x * old->y + 2. *
			old->x * old->x * old->y * old->y * old->y + old->y * old->y *
			old->y * old->y * old->y + old->x * old->y) / divi);
		resre = new->x * new->x * new->x - 3. * new->x * new->y * new->y - 1.;
		resim = 3. * new->x * new->x * new->y - new->y * new->y * new->y;
		if (resre == -2 && resim == 0)
			break ;
	}
	return (ft_set_color_newton(new));
}

void	ft_expose_newton(t_env *env)
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
			ft_pixel_to_image(x, y, env, ft_iter_newton(&new, &old, env));
		}
	}
	x = -1;
	while (++x < 6)
		if (env->move[x])
			ft_move(env);
}
