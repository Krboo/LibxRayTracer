/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:46:23 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/24 13:22:52 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_sphere		*ft_new_sphere(double radius, t_color color, t_vec pos)
{
	t_sphere *s;

	if (!(s = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	s->radius = radius;
	s->color = color;
	s->pos = pos;
	return (s);
}

void			ft_add_sphere(t_sphere *start, t_sphere *new)
{
	while (start->next)
		start = start->next;
	start->next = new;
}

t_sphere		*ft_get_sphere(int fd)
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
	}
	if (ret == -1)
		exit(-1);
	return (ft_new_sphere(radius, color, pos));
}

t_sphere		*ft_get_spheres(int fd)
{
	char		*line;
	int			ret;
	t_sphere	*s;

	s = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (s == NULL)
				s = ft_get_sphere(fd);
			else
				ft_add_sphere(s, ft_get_sphere(fd));
		}
		if (ret == -1)
			exit(-1);
	}
	return (s);
}
