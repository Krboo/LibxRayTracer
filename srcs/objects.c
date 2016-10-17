/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:15:56 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/17 13:40:58 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int ft_sphere(t_scene *s, t_ray *r, double *d)
{
	double	b;
	double	c;
	double	discr;
	t_vec	dist;

	dist = sub_vect(&r->pos, s->sphere->pos);
	b = scale(&r->dir, &dist);
	c = scale(&dist, &dist) - (s->sphere->radius * s->sphere->radius);
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

int	ft_plan(t_scene *s, t_ray *r, double *d)
{
	double	num;
	double	denum;
	double	t;

	num = s->plan->dis - scale(s->plan->pos, &r->pos);
	denum = scale(s->plan->pos, &r->dir);
	t = num / denum;
	if (t > EPSI)
	{
		*d = t;
		return (1);
	}
	return (0);
}

/*int     ft_cylindre(t_scene *s, t_ray *r, double *d)
{
	t_vec  dist;
	double   a;
	double   b;
	double   c;
	double   t;

	dist = sub_vect(&r->pos, s->cylind->pos);
	a = r->dir.x * r->dir.x + r->dir.y * r->dir.y;
	b = 2 * (r->pos.x * r->dir.x + r->pos.y * r->dir.y);
	c = r->pos.x * r->pos.x + r->pos.y * r->pos.y - 1;
	t = b * b - 4 * (a * c);
	if (t > EPSI)
	{
		t = (-b - sqrtf(t) * s->cylind->radius) / a;
		if ((t > EPSI) && (t < *d))
		{
			*d = t;
			return (1);
		}
	}
	return (0);
}*/
