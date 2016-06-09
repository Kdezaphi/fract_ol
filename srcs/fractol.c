/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 15:56:21 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/12/01 17:03:26 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *env)
{
	if (env->fractal == 0)
		ft_expose_julia(env);
	else if (env->fractal == 1)
		ft_expose_mandel(env);
	else if (env->fractal == 2)
		ft_expose_newton(env);
	else if (env->fractal == 3)
		ft_expose_pytha(env);
	ft_calc_frametime(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

void	ft_pixel_to_image(int x, int y, t_env *env, int color)
{
	t_color	unc;
	int		i;
	int		end;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		unc.cv = mlx_get_color_value(env->mlx, color);
		i = 0;
		while (i < (env->bpp / 8))
		{
			if (env->end == 0)
				end = i;
			else
				end = 3 - i;
			env->addr[((env->bpp / 8) * x) + (y * env->sl) + i] = unc.oct[end];
			i++;
		}
	}
}

void	ft_run_mlx(t_env *env)
{
	env->addr = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->end);
	mlx_hook(env->win, KEYPRESS, KEYPRESSMASK, &key_press, env);
	mlx_hook(env->win, KEYRELEASE, KEYRELEASEMASK, &key_release, env);
	mlx_hook(env->win, MOTIONNOTIFY, POINTERMOTIONMASK, &mouse_motion_hook,
		env);
	mlx_hook(env->win, BUTTONPRESS, BUTTONPRESSMASK, &mouse_button_press, env);
	mlx_loop_hook(env->mlx, &expose_hook, env);
	mlx_loop(env->mlx);
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac > 1)
	{
		if ((env.mlx = mlx_init()))
			if (!ft_init(&env, av[1]))
			{
				if ((env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT)))
					if ((env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT,
						"Test")))
						ft_run_mlx(&env);
				if (errno)
					perror(strerror(errno));
			}
	}
	else
		ft_init(&env, "");
	return (0);
}
