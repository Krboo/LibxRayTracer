/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:39:39 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/18 18:06:41 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj			*ft_get_cone(char **line, int i)
{
	double	alpha;
	t_color	color;
	t_vec	pos;
	t_vec	rot;

	while (!ft_strstr(line[i], "-------"))
	{
		if (ft_strstr(line[i], "pos:"))
			pos = ft_vector(line[i + 1]);
		if (ft_strstr(line[i], "alpha:"))
			alpha = ft_data(line[i + 1]);
		if (ft_strstr(line[i], "color:"))
			color = ft_color(line[i + 1]);
		if (ft_strstr(line[i], "rot:"))
			rot = ft_vector(line[i + 1]);
		i++;
	}
	return (ft_new_obj3(alpha, pos, rot, color));
}

t_obj		*ft_get_cones(char **line, t_env *env, int i)
{
	t_obj	*first;

	first = env->obj;
	while (ft_strcmp("-------", line[i]))
	{
		if (ft_strstr(line[i], "new:"))
		{
			if (!env->obj)
			{
				env->obj = ft_get_cone(line, i);
				first = env->obj;
			}
			else
					ft_add_obj(env->obj, ft_get_cone(line, i));
		}
		i++;
	}
	return (first);
}
