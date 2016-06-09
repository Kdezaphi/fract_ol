/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 15:26:24 by kdezaphi          #+#    #+#             */
/*   Updated: 2015/11/25 16:44:48 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECT_H
# define LIBVECT_H

# include "libft.h"
# include <math.h>
# include <stdlib.h>

typedef struct	s_vertex
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vertex;

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vector;

typedef struct	s_proj
{
	double	fov;
	double	ratio;
	double	near;
	double	far;
}				t_proj;

t_vertex		*vtxnew(double x, double y, double z, double w);
t_vector		*vtcnew(t_vertex *dest, t_vertex *orig);
double			vtcmagn(t_vector *vtc);
t_vector		*vtcnorm(t_vector *vtc);
t_vector		*vtcadd(t_vector *vtc1, t_vector *vtc2);
t_vector		*vtcsub(t_vector *vtc1, t_vector *vtc2);
t_vector		*vtcopp(t_vector *vtc);
t_vector		*vtcscalprod(t_vector *vtc, double k);
double			vtcdotprod(t_vector *vtc1, t_vector *vtc2);
t_vector		*vtccrossprod(t_vector *vtc1, t_vector *vtc2);
double			vtccos(t_vector *vtc1, t_vector *vtc2);
double			**mtxnew(const char *type, double arg, t_vector *vtc,
	t_proj *proj);
double			**mtxtrans(double **mtx);
double			**mtxmult(double **mtx1, double **mtx2);
t_vertex		*transvtx(double **mtx, t_vertex *vtx);
void			mtxfree(double **mtx);

#endif
