/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 17:08:16 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/02/02 17:08:17 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_square(t_coord **carre, int color, t_env *env)
{
	t_pos	first;
	t_pos	last;
	int		y;

	y = -1;
	first.x = WIDTH;
	last.x = 0;
	first.y = HEIGHT;
	last.y = 0;
	while (++y < 4)
	{
		first.x = (carre[y]->x < first.x) ? carre[y]->x : first.x;
		last.x = (carre[y]->x > last.x) ? carre[y]->x : last.x;
		first.y = (carre[y]->y < first.y) ? carre[y]->y : first.y;
		last.y = (carre[y]->y > last.y) ? carre[y]->y : last.y;
	}
	while (++first.x < last.x)
	{
		y = first.y - 1;
		while (++y < last.y)
			ft_pixel_to_image(first.x, y, env, color);
	}
}

void	ft_set_diamond(t_coord **carre, t_pos *first, t_pos *last, t_pos *mid)
{
	int		i;

	mid->x = 0;
	mid->y = 0;
	first->x = WIDTH;
	first->y = HEIGHT;
	last->y = 0;
	i = -1;
	while (++i < 4)
	{
		if (carre[i]->x < first->x)
		{
			first->x = carre[i]->x;
			mid->y = carre[i]->y;
		}
		if (carre[i]->y < first->y)
		{
			first->y = carre[i]->y - 1;
			mid->x = carre[i]->x + 1;
		}
		if (carre[i]->y > last->y)
			last->y = carre[i]->y;
	}
}

void	ft_draw_diamond(t_coord **carre, int color, t_env *env)
{
	t_pos	first;
	t_pos	last;
	t_pos	mid;
	int		x;
	int		len;

	ft_set_diamond(carre, &first, &last, &mid);
	len = -1;
	while (++first.y < last.y)
	{
		if (first.y < mid.y)
		{
			len += 2;
			mid.x--;
		}
		else
		{
			len -= 2;
			mid.x++;
		}
		x = mid.x - 1;
		while (++x < len + mid.x)
			ft_pixel_to_image(x, first.y, env, color);
	}
}
