/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 16:58:10 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/17 17:02:17 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj			*ft_get_plan(char **line, int i)
{
	double	dis;
	t_color	color;
	t_vec	pos;
	t_vec	rot;

	while (ft_strcmp(line[i], "-------"))
	{
		if (ft_strstr(line[i], "pos:"))
			pos = ft_vector(line[i + 1]);
		if (ft_strstr(line[i], "dis:"))
			dis = ft_atodouble(&line[i + 1]);
		if (ft_strstr(line[i], "color:"))
			color = ft_color(line[i + 1]);
		if (ft_strstr(line[i], "rot:"))
			rot = ft_vector(line[i + 1]);
		i++;
	}
	return (ft_new_obj(dis, pos, rot, color));
}

t_obj			*ft_get_plans(char **line, t_env *env, int i)
{
	t_obj	*first;

	first = env->obj;
	while (ft_strcmp("-------", line[i]))
	{
		if (ft_strstr(line[i], "new:"))
		{
			if (!env->obj)
			{
				env->obj = ft_get_plan(line, i);
				first = env->obj;
			}
			else
				ft_add_obj(env->obj, ft_get_plan(line, i));
		}
		i++;
	}
	return (first);
}
