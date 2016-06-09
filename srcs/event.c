/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 17:03:41 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/25 11:59:56 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(t_env *env)
{
	if (env->move[0])
		env->movex += (env->fractal < 3) ? 0.01 / env->zoom : 0.5 / env->zoom;
	if (env->move[1])
		env->movey += (env->fractal < 3) ? 0.01 / env->zoom : 0.5 / env->zoom;
	if (env->move[2])
		env->movex -= (env->fractal < 3) ? 0.01 / env->zoom : 0.5 / env->zoom;
	if (env->move[3])
		env->movey -= (env->fractal < 3) ? 0.01 / env->zoom : 0.5 / env->zoom;
	if (env->move[4])
	{
		if (env->plus > 4)
			env->plus /= 2;
		if (env->iter > 2)
			env->iter -= (env->fractal < 3) ? 64 : 2;
	}
	if (env->move[5])
	{
		if (env->plus < 2147483647)
			env->plus *= 2;
		if (env->iter < 10000)
			env->iter += (env->fractal < 3) ? 64 : 2;
	}
	if (env->fractal > 2)
		ft_redraw(env);
}

int		key_press(int keycode, t_env *env)
{
	if (keycode == 124)
		env->move[0] = 1;
	if (keycode == 125)
		env->move[1] = 1;
	if (keycode == 123)
		env->move[2] = 1;
	if (keycode == 126)
		env->move[3] = 1;
	if (keycode == 78)
		env->move[4] = 1;
	if (keycode == 69)
		env->move[5] = 1;
	if (keycode == 53)
		exit(0);
	if (keycode == 67 || keycode == 75)
	{
		if (keycode == 67)
			mouse_button_press(4, env->x, env->y, env);
		else
			mouse_button_press(5, env->x, env->y, env);
	}
	return (0);
}

int		key_release(int keycode, t_env *env)
{
	if (keycode == 49)
	{
		if (env->lock_c)
		{
			env->lock_c = 0;
			return (0);
		}
		env->lock_c = 1;
	}
	if (keycode == 124)
		env->move[0] = 0;
	if (keycode == 125)
		env->move[1] = 0;
	if (keycode == 123)
		env->move[2] = 0;
	if (keycode == 126)
		env->move[3] = 0;
	if (keycode == 78)
		env->move[4] = 0;
	if (keycode == 69)
		env->move[5] = 0;
	return (0);
}

int		mouse_motion_hook(int x, int y, t_env *env)
{
	env->x = x;
	env->y = y;
	if (!env->lock_c)
	{
		env->cre = x / (double)WIDTH * 2 - 1.;
		env->cim = (HEIGHT - y) / (double)HEIGHT;
	}
	return (0);
}

int		mouse_button_press(int button, int x, int y, t_env *env)
{
	if (button == 4 || button == 5)
	{
		env->movex += (x >= WIDTH / 2) ? 0.04 / env->zoom : -0.04 / env->zoom;
		env->movey += (y >= HEIGHT / 2) ? 0.06 / env->zoom : -0.06 / env->zoom;
		if (button == 4)
		{
			env->zoom *= 1.03;
			if (env->fractal < 3)
				env->iter += (env->zoom > 1 && env->iter < 2500) ? 64 : 0;
			else
				env->iter += (env->zoom > 1 && env->iter < 16) ? 2 : 0;
		}
		if (button == 5)
		{
			env->zoom /= 1.03;
			if (env->fractal < 3)
				env->iter -= (env->iter > 64) ? 64 : 0;
			else
				env->iter -= (env->iter > 4) ? 2 : 0;
		}
		if (env->fractal > 2)
			ft_redraw(env);
	}
	return (0);
}
