/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:22:09 by pmartine          #+#    #+#             */
/*   Updated: 2016/12/13 12:51:31 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double		min_max(double numb, double min, double max)
{
	if (numb < min)
		numb = min;
	if (numb > max)
		numb = max;
	return (numb);
}

double		shadow_loop(t_obj *node, t_env *e, double yo, t_calc calc)
{
	double	dis;

	dis = 0;
	if (node->type == 3)
		dis = ft_cylindre(node, e);
	else if (node->type == 2)
		dis = ft_cone(node, e);
	else if (node->type == 0)
		dis = ft_plan(node, e);
	else if (node->type == 1)
		dis = ft_sphere(node, e);
	if (dis > EPSI && dis < e->d)
	{
		e->cam_pos = calc.v2;
		e->ray_dir = calc.v3;
		e->d = yo;
		return (1);
	}
	else
		return (0);
}

double		shadow(t_env *e, t_obj *obj, t_vec cam)
{
	t_obj		*node;
	double		yo;
	t_calc		calc;

	yo = e->d;
	calc.v1 = sub_vect(e->spots->pos, cam);
	e->d = sqrtf(dot_vect(calc.v1, calc.v1));
	calc.v1 = norm_vect(calc.v1);
	node = e->obj;
	calc.v2 = e->cam_pos;
	calc.v3 = e->ray_dir;
	e->ray_dir = calc.v1;
	e->cam_pos = cam;
	while (node != NULL)
	{
		if (obj != node)
			if (shadow_loop(node, e, yo, calc) == 1)
				return (1);
		node = node->next;
	}
	e->cam_pos = calc.v2;
	e->ray_dir = calc.v3;
	e->d = yo;
	return (0);
}

double		calc_lamb(t_env *env, t_obj *obj)
{
	t_vec	dist;
	t_calc	c;
	double	lambert;
	double	tmp;
	double	spec;

	c.v1 = add_vect(env->cam_pos, scale_vect(env->ray_dir, env->d));
	c.v2 = normale(obj, env, c.v1);
	dist = sub_vect(env->spots->pos, c.v1);
	dist = norm_vect(dist);
	lambert = 0;
	spec = 0;
	c.v3 = scale_vect(c.v2, (2.0 * dot_vect(c.v2, dist)));
	c.v3 = sub_vect(dist, c.v3);
	if ((tmp = dot_vect(c.v3, env->ray_dir)) > 0.0)
		spec = pow(tmp, 30.0);
	lambert += dot_vect(dist, c.v2);
	lambert = min_max(lambert, 0.15, 0.84);
	if (spec > EPSI && obj->type != 0)
		lambert += spec;
	if (shadow(env, obj, c.v1) == (1))
		return (0.2);
	return (min_max(lambert, 0.15, 1.5));
}
