/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:46:23 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/14 15:41:29 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj		*ft_get_sphere(int fd)
{
	char	*line;
	double	radius;
	int 	ret;
	t_color	color;
	t_vec	pos;
	t_vec	rot;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (ft_strstr(line, "pos"))
		{
			pos = ft_vector(fd);
			free(line);
		}
		if (ft_strstr(line, "radius:"))
		{
			free(line);
			ret = get_next_line(fd, &line);
			radius = ft_atodouble(&line);
			//free(line);
		}
		if (ft_strstr(line, "color:"))
		{
			color = ft_color(fd);
			free(line);
		}
		rot = new_vec(0, 0, 0);
	}
	free(line);
	if (ret == -1)
		exit(-1);
	return (ft_new_obj2(radius, pos, rot, color));
}

t_obj		*ft_get_spheres(int fd, t_env *env)
{
	char		*line;
	int			ret;
	t_obj		*first;

	first = env->obj;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (!env->obj)
			{
				env->obj = ft_get_sphere(fd);
				first = env->obj;
			}
			else
				ft_add_obj(env->obj, ft_get_sphere(fd));
		}
		free(line);
		if (ret == -1)
			exit(-1);
	}
	if (line)
		free(line);
	return (first);
}
