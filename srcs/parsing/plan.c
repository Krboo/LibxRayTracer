/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 16:58:10 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/25 11:58:09 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj			*ft_get_plan(int fd, t_vec rot)
{
	char	*line;
	double	dis;
	int		ret;
	t_color	color;
	t_vec	pos;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (ft_strstr(line, "pos:"))
			pos = ft_vector(fd);
		if (ft_strstr(line, "dis:"))
		{
			ret = get_next_line(fd, &line);
			dis = ft_atodouble(&line);
		}
		if (ft_strstr(line, "color:"))
			color = ft_color(fd);
		if (ft_strstr(line, "rot:"))
			rot = ft_vector(fd);
	}
	if (ret == -1)
		exit(-1);
	return (ft_new_obj(dis, pos, rot, color));
}

t_obj			*ft_get_plans(int fd)
{
	char	*line;
	int		ret;
	t_obj	*obj;
	t_vec	rot;

	obj = NULL;
	rot = new_vec(0.0,0.0,0.0); //?
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (obj == NULL)
				obj = ft_get_plan(fd, rot);
			else
				ft_add_obj(obj, ft_get_plan(fd, rot));
		}
		if (ret == -1)
			exit(-1);
	}
	return (obj);
}
