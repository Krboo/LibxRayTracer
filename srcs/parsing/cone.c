/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:39:39 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/24 13:22:12 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_cone			*ft_new_cone(double alpha, t_color color, t_vec pos)
{
	t_cone	*c;

	if (!(c = (t_cone *)malloc(sizeof(t_cone))))
		return (NULL);
	c->alpha = alpha;
	c->color = color;
	c->pos = pos;
	return (c);
}

void			ft_add_cone(t_cone *start, t_cone *new)
{
	while (start->next)
		start = start->next;
	start->next = new;
}

t_cone			*ft_get_cone(int fd)
{
	char	*line;
	double	alpha;
	int		ret;
	t_color	color;
	t_vec	pos;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "--------"))
	{
		if (ft_strstr(line, "pos:"))
			pos = ft_vector(fd);
		if (ft_strstr(line, "alpha:"))
		{
			ret = get_next_line(fd, &line);
			alpha = ft_atodouble(&line);
		}
		if (ft_strstr(line, "color:"))
			color = ft_color(fd);
	}
	if (ret == -1)
		exit(-1);
	return (ft_new_cone(alpha, color, pos));
}

t_cone			*ft_get_cones(int fd)
{
	char	*line;
	int		ret;
	t_cone	*c;

	c = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (c == NULL)
				c = ft_get_cone(fd);
			else
				ft_add_cone(c, ft_get_cone(fd));
		}
		if (ret == -1)
			exit(-1);
	}
	return (c);
}
