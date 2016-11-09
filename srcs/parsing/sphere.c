/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:46:23 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/09 17:03:28 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj		*ft_get_sphere(int fd, t_vec rot)
{
	char	*line;
	double	radius;
	int 	ret;
	t_color	color;
	t_vec	pos;
	t_obj	*obj;

	obj = NULL;
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
	obj = ft_new_obj2(radius, pos, rot, color);
	if (ret == -1)
		exit(-1);
	return (obj);
}

void		ft_get_spheres(int fd, t_env *env)
{
	char		*line;
	int			ret;
	t_vec		rot;

	rot = new_vec(0.0,0.0,0.0);   //?
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (!env->obj->type)
			{
				free(env->obj);
				env->obj = ft_get_sphere(fd, rot);
			}
			else
			{
				ft_add_obj(env->obj, ft_get_sphere(fd, rot));
			}
		}
		free(line);
		if (ret == -1)
			exit(-1);
	}
	free(line);
}
