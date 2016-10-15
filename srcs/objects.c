/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:15:56 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/15 18:00:40 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void ft_init_sphere(t_obj *s, t_scene *sc)
{
	s->pos.x = sc->sphere->pos->x;
	s->pos.y = sc->sphere->pos->y;
	s->pos.z = sc->sphere->pos->z;
	s->radius = sc->sphere->radius;
	s->color = RED;
}

int ft_sphere(t_obj *s, t_ray *r, double *d)
{
	double	b;
	double	c;
	double	discr;
	t_vec	dist;

	dist = sub_vect(&r->pos, &s->pos);
	b = scale(&r->dir, &dist);
	c = scale(&dist, &dist) - (s->radius * s->radius);
	discr = b * b - c;
	if (discr > EPSI)
	{
		discr = -b - sqrtf(discr);
		if ((discr > EPSI) && (discr < *d))
		{
			*d = discr;
			return (1);
		}
	}
	return (0);
}

void ft_init_plan(t_obj *s)
{
	s->pos.x = 0;
	s->pos.y = 0;
	s->pos.z = 42;
}

int	ft_plan(t_obj *p, t_ray *r, double *d)
{
	double	num;
	double	denum;
	double	t;

	num = p->d - scale(&p->dir, &r->pos);
	denum = scale(&p->dir, &r->dir);
	t = num / denum;
	if (t > EPSI)
	{
		*d = t;
		return (1);
	}
	return (0);
}
