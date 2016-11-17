/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:46:23 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/17 17:44:22 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj		*ft_get_sphere(char **line, int i)
{
	double	radius;
	t_color	color;
	t_vec	pos;
	t_vec	rot;

	while (ft_strcmp(line[i], "-------"))
	{
		if (ft_strstr(line[i], "pos"))
			pos = ft_vector(line[i + 1]);
		if (ft_strstr(line[i], "radius:"))
			radius = ft_atodouble(&line[i + 1]);
		if (ft_strstr(line[i], "color:"))
			color = ft_color(line[i + 1]);
		i++;
	}
	rot = new_vec(0, 0, 0);
	return (ft_new_obj2(radius, pos, rot, color));
}

t_obj		*ft_get_spheres(char **line, t_env *env, int i)
{
	t_obj		*first;

	first = env->obj;
	while (ft_strcmp("-------", line[i]))
	{
		if (ft_strstr(line[i], "new:"))
		{
			if (!env->obj)
			{
				env->obj = ft_get_sphere(line, i);
				first = env->obj;
			}
			else
				ft_add_obj(env->obj, ft_get_sphere(line, i));
		}
		i++;
	}
	return (first);
}
