/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:57:26 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/24 12:26:08 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_cam		*ft_get_camera(int fd)
{
	char		*line;
	int 		ret;
	t_cam		*c;

	c = (t_cam *)malloc(sizeof(c));
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (ft_strstr(line, "pos:"))
			c->pos = ft_vector(fd);
		if (ft_strstr(line, "dir:"))
			c->dir = ft_vector(fd);
	}
	return (c);
}
