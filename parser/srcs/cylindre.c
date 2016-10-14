/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:50:13 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/14 16:05:44 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

t_cylind		*ft_new_cylind(double radius, t_color *color, t_pos *pos)
{
	t_cylind	*c;

	if (!(c = (t_cylind *)malloc(sizeof(t_cylind))))
		return (NULL);
	c->radius = radius;
	c->color = color;
	c->pos = pos;
	return (c);
}

void			ft_add_cylind(t_cylind	*start, t_cylind *new)
{
	while (start->next)
		start = start->next;
	start->next = new;
}

t_cylind		*ft_get_cylind(int fd)
{
	char	*line;
	double	radius;
	int		ret;
	t_color	*color;
	t_pos	*pos;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (ft_strstr(line, "pos:"))
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
	return (ft_new_cylind(radius, color, pos));
}

t_cylind		*ft_get_cylinds(int fd)
{
	char		*line;
	int			ret;
	t_cylind	*c;

	c = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (c == NULL)
				c = ft_get_cylind(fd);
			else
				ft_add_cylind(c, ft_get_cylind(fd));
		}
		if (ret == -1)
			exit(-1);
	}
	return (c);
}
