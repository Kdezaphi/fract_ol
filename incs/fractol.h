/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 16:28:41 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/12/01 18:13:30 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 750
# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define MOTIONNOTIFY 6
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define BUTTONPRESSMASK (1L<<2)
# define POINTERMOTIONMASK (1L<<6)

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sl;
	int				end;
	char			*addr;
	double			movex;
	double			movey;
	int				iter;
	int				lock_c;
	int				fractal;
	int				move[6];
	int				x;
	int				y;
	unsigned int	plus;
	double			cre;
	double			cim;
	double			zoom;
	double			time;
	double			frametime;
	double			oldtime;
}				t_env;

typedef struct	s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef union	u_color
{
	char	oct[4];
	int		cv;
}				t_color;

void			ft_calc_frametime(t_env *env);
void			ft_redraw(t_env *env);
void			ft_move(t_env *env);
t_coord			**ft_trans_hor(t_coord **oldcarre);
t_coord			**ft_trans_ahor(t_coord **oldcarre);
void			ft_draw_square(t_coord **carre, int color, t_env *env);
void			ft_set_diamond(t_coord **carre, t_pos *first, t_pos *last,
	t_pos *mid);
void			ft_draw_diamond(t_coord **carre, int color, t_env *env);
void			ft_free_square(t_coord **carre);
int				ft_expose_pytha(t_env *env);
int				ft_iter_julia(t_coord *new, t_coord *old, t_env *env);
void			ft_expose_julia(t_env *env);
int				ft_iter_mandel(t_coord *new, t_coord *old, t_coord *nbr,
	t_env *env);
void			ft_expose_mandel(t_env *env);
int				ft_iter_newton(t_coord *new, t_coord *old, t_env *env);
void			ft_expose_newton(t_env *env);
int				expose_hook(t_env *env);
int				key_press(int keycode, t_env *env);
int				key_release(int keycode, t_env *env);
int				ft_init_name(int fractal, t_env *env);
int				ft_check_name(char *name, t_env *env);
int				ft_init(t_env *env, char *name);
void			ft_pixel_to_image(int x, int y, t_env *env, int color);
int				ft_set_color(int i, t_env *env);
int				mouse_motion_hook(int x, int y, t_env *env);
int				mouse_button_press(int button, int x, int y, t_env *env);
void			ft_run_mlx(t_env *env);

#endif
