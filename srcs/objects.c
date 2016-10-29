/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:15:56 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/29 15:46:50 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	mini(double d1, double d2)
{
	if (d1 > d2)
		return (d2);
	else
		return (d1);
}

double ft_sphere(t_obj *obj, t_env *e)
{
	double	a;
	double	b;
	double	c;
	double	discr;
	t_vec	dist;

	dist = sub_vect(e->cam_pos, obj->pos);
	a = dot_vect(e->ray_dir ,e->ray_dir);
	b = 2 * dot_vect(e->ray_dir, dist);
	c = dot_vect(dist, dist) - (obj->size * obj->size);
	discr = b * b - 4 * a * c;
	if (discr > EPSI)
	{
		c = ((-b - sqrtf(discr)) / (2 * a));
		discr = ((-b + sqrtf(discr)) / (2 * a));
		discr = discr < c ? discr : c;
		if ((discr > EPSI) && (discr < e->d))
		{
			e->d = discr;
			return (1);
		}
	}
	return (0);
}
double	ft_plan(t_obj	*node, t_env *env)
	{
	double	t;

	t = ((node->size - dot_vect(node->pos, env->ray_pos)) / dot_vect(node->pos, env->ray_dir));
	if (t > EPSI && t < env->d)
	{
		env->d = t;
		return (1);
	}
	return (0);
}
/*
int     ft_cylindre(t_env *e, double *d)
{
	t_vec  dist;
	double   a;
	double   b;
	double   c;
	double   t;

//	dist = sub_vect(e->ray_pos, e->s->cylind->pos);
//	a = r->dir.x * r->dir.x + r->dir.y * r->dir.y;
	b = 2 * (e->ray_pos.x * e->ray_dir.x + e->ray_pos.y * e->ray_dir.y);
	c = e->ray_pos.x * e->ray_pos.x + e->ray_pos.y * e->ray_pos.y - 1;
	t = b * b - 4 * (a * c);
	if (t > EPSI)
	{
//		t = (-b + sqrtf(t) * s->cylind->radius) / a;
		if ((t > EPSI) && (t < *d))
		{
			*d = t;
			return (1);
		}
	}
	return (0);
}

int		ft_intersections(t_scene *s, double *d)
{
	if (ft_sphere(s,s->ray,d) == 1 || ft_plan(s,s->ray,d) == 1)
		return (1);
	return (0);
}*/
