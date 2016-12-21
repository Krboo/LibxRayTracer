/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:23:05 by pmartine          #+#    #+#             */
/*   Updated: 2016/12/20 16:14:43 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_obj		*inter_loop(t_obj *node, t_env *e, t_obj *tmp, t_obj lum)
{
	while (node != NULL)
	{
		if (node->type == 3)
			e->dist = ft_cylindre(node, e);
		if (node->type == 2)
			e->dist = ft_cone(node, e);
		if (node->type == 0)
			e->dist = ft_plan(node, e);
		if (node->type == 1)
			e->dist = ft_sphere(node, e);
		if (e->dist > EPSI && e->dist < e->d)
		{
			tmp = node;
			e->d = e->dist;
		}
		node = node->next;
	}
	e->dist = ft_sphere(&lum, e);
	if (e->dist > EPSI && e->dist < e->d)
	{
		tmp = &lum;
		e->d = e->dist;
	}
	return (tmp);
}

double	deg_to_rad(double deg)
{
	double	rad;

	rad = (M_PI * deg) / 180;
	return (rad);
}

t_vec		inv(t_vec	norm)
{
	t_vec		res;

	res.x = norm.x * -1;
	res.y = norm.y * -1;
	res.z = norm.z * -1;
	return (res);
}

t_obj		*fonct_plan(t_obj *obj)
{
	//if ((obj->rot.x * obj->pos.x) > 0)
			obj->rot.x = obj->rot.x * -1;
	//if ((obj->rot.y * obj->pos.y) > 0)
			obj->rot.y = obj->rot.y * -1;
	//if ((obj->rot.z * obj->pos.z) > 0)
			obj->rot.z = obj->rot.z * -1;
	return (obj);
}

void		putdisplay(t_env *env)
{
	ft_putendl("-----current scene-----");
	putcam(env);
	putlight(env);
	putobj(env);
	ft_putendl("-----------------------");
}
