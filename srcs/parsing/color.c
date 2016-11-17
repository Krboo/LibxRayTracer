/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:31:49 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/15 15:20:13 by qduperon         ###   ########.fr       */
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

t_color		ft_color(char *line)
{
	double	r;
	double	g;
	double	b;
	
	r = ft_atodouble(&line);
	g = ft_atodouble(&line);
	b = ft_atodouble(&line);
	return (ft_new_color(r, g, b));
}
