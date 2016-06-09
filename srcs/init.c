/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 17:05:19 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/25 11:59:34 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calc_frametime(t_env *env)
{
	env->oldtime = env->time;
	env->time = clock();
	env->frametime = (env->time - env->oldtime) / 1000000.0;
}

void	ft_redraw(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	if ((env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT)))
		env->addr = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->end);
}

int		ft_init_name(int fractal, t_env *env)
{
	if (fractal == 0)
		env->movex = 0;
	else if (fractal == 1)
	{
		env->movex = -0.75;
		env->lock_c = 1;
	}
	else if (fractal == 3)
	{
		env->cre = -1;
		env->lock_c = 1;
	}
	return (fractal);
}

int		ft_check_name(char *name, t_env *env)
{
	int		i;
	int		fractal;
	char	*namelow;

	i = -1;
	namelow = (char*)malloc(ft_strlen(name) + 1);
	while (name[++i])
		namelow[i] = ft_tolower(name[i]);
	namelow[i] = '\0';
	if (!ft_strcmp("julia", namelow))
		fractal = ft_init_name(0, env);
	else if (!ft_strcmp("mandelbrot", namelow))
		fractal = ft_init_name(1, env);
	else if (!ft_strcmp("newton", namelow))
		fractal = 2;
	else if (!ft_strcmp("pythagore", namelow))
		fractal = ft_init_name(3, env);
	else
	{
		ft_putstr_fd("usage: ./fractol [julia | mandelbrot | newton", 2);
		ft_putendl_fd(" | pythagore]", 2);
		fractal = -1;
	}
	free(namelow);
	return (fractal);
}

int		ft_init(t_env *env, char *name)
{
	int		i;

	i = -1;
	env->cre = 0;
	env->cim = 0;
	env->zoom = 1.;
	env->movey = 0;
	env->time = 0;
	env->oldtime = 0;
	env->lock_c = 0;
	env->plus = 4;
	if ((env->fractal = ft_check_name(name, env)) < 0)
		return (1);
	env->iter = (env->fractal < 3) ? 64 : 4;
	while (++i < 6)
		env->move[i] = 0;
	return (0);
}
