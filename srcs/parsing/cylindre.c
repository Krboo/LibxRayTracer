/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:50:13 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/23 18:35:41 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj		*ft_get_cylind(char **line, int i)
{
	double	radius;
	t_color	color;
	t_vec	pos;
	t_vec	rot;

	while (!ft_strstr(line[i], "-------"))
	{
		if (ft_strstr(line[i], "pos:"))
			pos = ft_vector(line[i + 1]);
		if (ft_strstr(line[i], "radius:"))
			radius = ft_data(line[i + 1]);
		if (ft_strstr(line[i], "color:"))
			color = ft_color(line[i + 1]);
		if (ft_strstr(line[i], "rot:"))
			rot = ft_vector(line[i + 1]);
		i++;
	}
	return (ft_new_obj4(radius, pos, rot, color));
}

t_obj		*ft_get_cylinds(char **line, t_env *env, int i)
{
	t_obj	*first;

	first = env->obj;
	while (!ft_strstr("-------", line[i]))
	{
		if (ft_strstr(line[i], "new:"))
		{
			if (!env->obj)
			{
				env->obj = ft_get_cylind(line, i);
				first = env->obj;
			}
			else
				ft_add_obj(env->obj, ft_get_cylind(line, i));
		}
		i++;
	}
	return (first);
}
