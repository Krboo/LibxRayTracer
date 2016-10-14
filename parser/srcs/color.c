/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:31:49 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/14 15:22:12 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

t_color		*ft_new_color(double r, double g, double b)
{
	t_color	*c;

	if (!(c = (t_color *)malloc(sizeof(t_color))))
		return (NULL);
	c->red = r;
	c->green = g;
	c->blue = b;
	return (c);
}

t_color		*ft_color(int fd)
{
	char	*line;
	double	r;
	double	g;
	double	b;

	if (get_next_line(fd, &line) < 1)
		exit(-1);
	r = ft_atodouble(&line);
	g = ft_atodouble(&line);
	b = ft_atodouble(&line);
	return (ft_new_color(r, g, b));
}

void		ft_deleted_color(t_color *color)
{
	free(color);
}
