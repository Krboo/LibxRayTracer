/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 16:58:10 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/14 15:35:46 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj			*ft_get_plan(int fd)
{
	char	*line;
	double	dis;
	int		ret;
	t_color	color;
	t_vec	pos;
	t_vec	rot;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (ft_strstr(line, "pos:"))
		{
			pos = ft_vector(fd);
			free(line);
		}
		if (ft_strstr(line, "dis:"))
		{
			free(line);
			ret = get_next_line(fd, &line);
			dis = ft_atodouble(&line);
		}
		if (ft_strstr(line, "color:"))
		{
			color = ft_color(fd);
			free(line);
		}
		if (ft_strstr(line, "rot:"))
		{
			rot = ft_vector(fd);
			free(line);
		}
	}
	free(line);
	if (ret == -1)
		exit(-1);
	return (ft_new_obj(dis, pos, rot, color));
}

t_obj			*ft_get_plans(int fd, t_env *env)
{
	char	*line;
	int		ret;
	t_obj	*first;

	first = env->obj;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (!env->obj)
			{
				env->obj = ft_get_plan(fd);
				first = env->obj;
			}
			else
				ft_add_obj(env->obj, ft_get_plan(fd));
		}
		free(line);
		if (ret == -1)
			exit(-1);
	}
	if (line)
		free(line);
	return (first);
}
