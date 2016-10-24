/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:00:12 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/24 17:23:42 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj			*ft_get_spot(int fd, t_vec rot)
{
	char	*line;
	int		ret;
	t_color	color;
	t_vec	pos;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (ft_strstr(line, "pos:"))
			pos = ft_vector(fd);
		if (ft_strstr(line, "color:"))
			color = ft_color(fd);
		rot = new_vec(0, 0, 0);
	}
	if (ret == -1)
		exit(-1);
	return (ft_new_obj5(pos, rot, color));
}

t_obj			*ft_get_spots(int fd)
{
	char	*line;
	int		ret;
	t_obj	*s;
	t_vec	rot;

	s = NULL;
	rot = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (s == NULL)
				s = ft_get_spot(fd, rot);
			else
				ft_add_spot(s, ft_get_spot(fd, rot));
		}
		if (ret == -1)
			exit(-1);
	}
	return (s);
}
