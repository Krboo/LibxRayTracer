/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:00:12 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/25 12:13:35 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_spot			*ft_get_spot(int fd)
{
	char	*line;
	double	size;
	int		ret;
	t_color	color;
	t_vec	pos;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (ft_strstr(line, "pos:"))
			pos = ft_vector(fd);
		if (ft_strstr(line, "color:"))
			color = ft_color(fd);
		if (ft_strstr(line, "size:"))
		{
			ret = get_next_line(fd, &line);
			size = ft_atodouble(&line);
		}
	}
	if (ret == -1)
		exit(-1);
	return (ft_new_spot(size, pos, color));
}

t_spot			*ft_get_spots(int fd)
{
	char	*line;
	int		ret;
	t_spot	*s;

	s = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("-------", line))
	{
		if (ft_strstr(line, "new:"))
		{
			if (s == NULL)
				s = ft_get_spot(fd);
			else
				ft_add_spot(s, ft_get_spot(fd));
		}
		if (ret == -1)
			exit(-1);
	}
	return (s);
}
