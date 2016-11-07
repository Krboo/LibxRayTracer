/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:00:12 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/07 15:54:43 by qduperon         ###   ########.fr       */
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
		{
			pos = ft_vector(fd);
			free(line);
		}
		if (ft_strstr(line, "color:"))
		{
			color = ft_color(fd);
			free(line);
		}
		if (ft_strstr(line, "size:"))
		{
			free(line);
			ret = get_next_line(fd, &line);
			size = ft_atodouble(&line);
		}
	}
	free(line);
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
		free(line);
		if (ret == -1)
			exit(-1);
	}
	free(line);
	return (s);
}
