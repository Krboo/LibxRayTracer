/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:15:56 by pmartine          #+#    #+#             */
/*   Updated: 2016/11/07 17:36:08 by pmartine         ###   ########.fr       */
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
/*double	ft_cylindre(t_obj *obj, t_env *e)
  {
  double	a;
  double	b;
  double	c;
  double	discr;
  t_vec	dist;

  dist = sub_vect(e->cam_pos, obj->pos);
  dist = norm_vect(dist);
  a = dot_vect(e->ray_dir ,e->ray_dir) - pow;
  b = 2 * dot_vect(e->ray_dir, dist);
  c = dot_vect(dist, dist) - (obj->size * obj->size);
  discr = b * b - 4 * a * c;
  c = ((-b + sqrtf(discr)) / (2 * a));
  discr = ((-b - sqrtf(discr)) / (2 * a));
  if (discr > c)
  discr = c;
  return (discr);
  }*/

t_obj	*ft_intersection(t_env *e, t_obj *node)
{
	t_obj	*tmp;
	double	dist;

	dist = 0;
	tmp = NULL;
	e->d = 80000.0;
	while (node != NULL)
	{
		//if (node->type == 3)
	//		dist = ft_inter_cone(mlx, node, ray, pos);
	//	else if (node->type == 2)
	//		dist = ft_inter_cylinder(mlx, node, ray, pos);
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
