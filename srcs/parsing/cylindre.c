/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:50:13 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/09 17:56:16 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj		*ft_get_cylind(int fd, t_vec rot)
{
	char	*line;
	double	radius;
	int		ret;
	t_color	color;
	t_vec	pos;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (ft_strstr(line, "pos:"))
		{
			pos = ft_vector(fd);
			free(line);
		}
		if (ft_strstr(line, "radius:"))
		{
			free(line);
			ret = get_next_line(fd, &line);
			radius = ft_atodouble(&line);
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
	return (ft_new_obj4(radius, pos, rot, color));
}

t_obj			*ft_get_cylinds(int fd, t_env *env)
{
	char		*line;
	int			ret;
	t_vec		rot;
	t_obj		*first;

	first = env->obj;
	rot = new_vec(0.0,0.0,0.0);
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (!env->obj)
			{
				env->obj = ft_get_cylind(fd, rot);
				first = env->obj;
			}
				else
				ft_add_obj(env->obj, ft_get_cylind(fd, rot));
		}
		free(line);
		if (ret == -1)
			exit(-1);
	}
	return (first);
}
