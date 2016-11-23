/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:15:56 by pmartine          #+#    #+#             */
/*   Updated: 2016/11/14 16:32:25 by pmartine         ###   ########.fr       */
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

double	ft_sphere(t_obj *obj, t_env *e)
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
	c = ((-b + sqrtf(discr)) / (2 * a));
	discr = ((-b - sqrtf(discr)) / (2 * a));
	if (discr > c)
		discr = c;
	return (discr);
}

double	ft_plan(t_obj	*node, t_env *env)
{
	double	t;

	t = ((dot_vect(node->rot, node->pos) - dot_vect(node->rot, env->cam_pos)) / dot_vect(node->rot, env->ray_dir));
	if (t < EPSI)
		return (-1);
	return (t);
}

double	ft_cylindre(t_obj *node, t_env *e)
{
	double	disc;
	double	a;
	double	b;
	double	c;
	t_vec	dist;
	double	t0;
	double	t1;

	dist = sub_vect(e->cam_pos, node->pos);
	//if (!(node->rot.x == 0 && node->rot.y == 0 && node->rot.z == 0))
	node->rot = norm_vect(node->rot);
	a = dot_vect(e->ray_dir, e->ray_dir) - pow(dot_vect(e->ray_dir, node->rot), 2);
	b = 2 * (dot_vect(e->ray_dir, dist) - dot_vect(e->ray_dir, node->rot) * dot_vect(dist, node->rot));
	c = dot_vect(dist, dist) - pow(dot_vect(dist, node->rot), 2) - pow(node->size, 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1);
	t0 = (-b + sqrtf(disc)) / (2 * a);
	t1 = (-b - sqrtf(disc)) / (2 * a);
	if (t0 > t1)
		t0 = t1;
	return (t0);
}

double	ft_cone(t_obj *node, t_env *e)
{
	double	disc;
	double	a;
	double	b;
	double	c;
	t_vec	dist;
	double	t0;
	double	t1;

	dist = sub_vect(e->cam_pos, node->pos);
//	if (!(node->rot.x == 0 && node->rot.y == 0 && node->rot.z == 0))
	node->rot = norm_vect(node->rot);
	a = dot_vect(e->ray_dir, e->ray_dir) - (1 + pow(tan(node->size), 2)) *
		pow(dot_vect(e->ray_dir, node->rot), 2);
	b = 2 * (dot_vect(e->ray_dir, dist) - (1 + pow(tan(node->size), 2)) *
			dot_vect(e->ray_dir, node->rot) * dot_vect(dist, node->rot));
	c = dot_vect(dist, dist) - (1 +	pow(tan(node->size), 2)) * pow(dot_vect(dist, node->rot), 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1);
	t0 = (-b + sqrtf(disc)) / (2 * a);
	t1 = (-b - sqrtf(disc)) / (2 * a);
	if (t0 > t1)
		t0 = t1;
	return (t0);
}

t_obj	*ft_intersection(t_env *e, t_obj *node)
{
	t_obj	*tmp;
	double	dist;

	dist = 0;
	tmp = NULL;
	e->d = 20000.0;
	while (node != NULL)
	{
		if (node->type == 3)
			dist = ft_cylindre(node, e);
		if (node->type == 2)
			dist = ft_cone(node, e);
		if (node->type == 0)
			dist = ft_plan(node, e);
		if (node->type == 1)
			dist = ft_sphere(node, e);
		if (dist > EPSI && dist < e->d)
		{
			tmp = node;
			e->d = dist;
		}
		node = node->next;
	}
	return (tmp);
}
