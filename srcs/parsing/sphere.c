/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:46:23 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/24 17:14:26 by qduperon         ###   ########.fr       */
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

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (ft_strstr(line, "pos"))
			pos = ft_vector(fd);
		if (ft_strstr(line, "radius:"))
		{
			ret = get_next_line(fd, &line);
			radius = ft_atodouble(&line);
		}
		if (ft_strstr(line, "color:"))
			color = ft_color(fd);
		rot = new_vec(0, 0, 0);
	}
	if (ret == -1)
		exit(-1);
	return (ft_new_obj2(radius, pos, rot, color));
}

t_obj		*ft_get_spheres(int fd)
{
	char		*line;
	int			ret;
	t_obj		*s;
	t_vec		rot;

	s = NULL;
	rot = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (s == NULL)
				s = ft_get_sphere(fd, rot);
			else
				ft_add_obj(s, ft_get_sphere(fd, rot));
		}
		if (ret == -1)
			exit(-1);
	}
	return (s);
}
