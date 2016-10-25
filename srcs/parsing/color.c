/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:31:49 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/25 12:02:06 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_color		ft_new_color(double r, double g, double b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_color		ft_color(int fd)
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
