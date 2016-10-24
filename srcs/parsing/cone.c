/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:39:39 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/24 16:46:28 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj			*ft_get_cone(int fd, t_vec rot)
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
		if (ft_strstr(line, "rot:"))
			rot = ft_vector(fd);
	}
	if (ret == -1)
		exit(-1);
	return (ft_new_obj3(alpha, pos, rot, color));
}

t_obj			*ft_get_cones(int fd)
{
	char	*line;
	int		ret;
	t_vec	rot;
	t_obj	*obj;

	obj = NULL;
	rot = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (obj == NULL)
				obj = ft_get_cone(fd, rot);
			else
				ft_add_obj(obj, ft_get_cone(fd, rot));
		}
		if (ret == -1)
			exit(-1);
	}
	return (obj);
}
