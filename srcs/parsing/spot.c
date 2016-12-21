/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:25:22 by pmartine          #+#    #+#             */
/*   Updated: 2016/12/07 10:25:25 by pmartine         ###   ########.fr       */
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
	{
		pos = ft_vector(line[i + 1]);
		pos.x += 0.15;
		pos.y += 0.15;
		pos.z += 0.15;
	}
		if (ft_strstr(line[i], "color:"))
			color = ft_color(line[i + 1]);
		if (ft_strstr(line[i], "size:"))
			size = ft_data(line[i + 1]);
		i++;
	}
	return (ft_new_spot(size, pos, color));
}

t_spot			*ft_get_spots(char **line, t_env *env, int i)
{
	t_spot	*s;

	s = env->spots;
	while (!ft_strstr("-------", line[i]))
	{
		if (ft_strstr(line[i], "new:"))
		{
			if (!env->spots)
			{
				env->spots = ft_get_spot(line, i);
				s = env->spots;
			}
			else
				ft_add_spot(s, ft_get_spot(line, i));
		}
		i++;
	}
	return (s);
}
