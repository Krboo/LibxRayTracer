/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:00:12 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/17 18:17:56 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_spot			*ft_get_spot(char **line, int i)
{
	double	size;
	t_color	color;
	t_vec	pos;

	while (!ft_strstr(line[i], "-------"))
	{
		if (ft_strstr(line[i], "pos:"))
			pos = ft_vector(line[i + 1]);
		if (ft_strstr(line[i], "color:"))
			color = ft_color(line[i + 1]);
		if (ft_strstr(line[i], "size:"))
			size = ft_atodouble(&line[i + 1]);
		i++;
	}
	return (ft_new_spot(size, pos, color));
}

t_spot			*ft_get_spots(char **line, int i)
{
	t_spot	*s;

	s = NULL;
	while (!ft_strstr("-------", line[i]))
	{
		if (ft_strstr(line[i], "new:"))
		{
			if (s == NULL)
				s = ft_get_spot(line, i);
			else
				ft_add_spot(s, ft_get_spot(line, i));
		}
		i++;
	}
	return (s);
}
