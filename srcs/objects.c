/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:15:56 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/13 19:49:35 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void ft_init_sphere(t_obj *s)
{
	s->pos.x = 0;
	s->pos.y = 0;
	s->pos.z = 45;
	s->radius = 15;
	s->color = RED;
}

int ft_sphere(t_obj *s, t_ray *r, float *d)
{
	float   b;
	float   c;
	float   discr;
	t_vec  dist;

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

int	ft_plan(t_obj *p, t_ray *r, float *d)
{
	float	num;
	float	denum;
	float	t;

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
