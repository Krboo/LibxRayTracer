/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:22:09 by pmartine          #+#    #+#             */
/*   Updated: 2016/12/22 16:06:55 by pmartine         ###   ########.fr       */
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

double		shadow_loop(t_obj *node, t_env *e, double temp, t_calc calc)
{
	double	dis;

	dis = 20000.0;
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
		e->d = temp;
		return (1);
	}
	else
		return (0);
}

int			special_test(t_env *e, t_obj *node, double num, t_calc calc)
{
	t_obj		co;

	co.pos = node->pos;
	co.size = node->size - 1;
	co.rot = node->rot;
	co.type = 2;
	co.col = node->col;
	if (shadow_loop(&co, e, num, calc) == 1)
		return (1);
	else
		return (0);
}

double		shadow(t_env *e, t_obj *obj, t_vec cam)
{
	t_obj		*node;
	double		yo;
	t_calc		calc;

	e->dist = 20000.0;
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
		if ((obj != node && shadow_loop(node, e, yo, calc) == 1) || \
			(node->type == 2 && special_test(e, node, yo, calc) == 1))
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
	lambert = 0.00;
	spec = 0.00;
	c.v3 = scale_vect(c.v2, (2.0 * dot_vect(c.v2, dist)));
	c.v3 = sub_vect(dist, c.v3);
	lambert = dot_vect(dist, c.v2);
	if ((tmp = dot_vect(c.v3, env->ray_dir)) > 0.0)
		spec = pow(tmp, 30.0);
	lambert = min_max(lambert, 0.00, 0.85);
	if (spec > EPSI && obj->type != 0)
		lambert += spec;
	if (shadow(env, obj, c.v1) == 1)
		return (0.00);
	return (min_max(lambert, 0.00, 1.5));
}
