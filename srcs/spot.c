/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:00:12 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/15 16:41:24 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_spot			*ft_new_spot(t_color *color, t_vec *pos)
{
	t_spot		*s;

	if (!(s = (t_spot *)malloc(sizeof(t_spot))))
		return (NULL);
	s->color = color;
	s->pos = pos;
	return (s);
}

void			ft_add_spot(t_spot *start, t_spot *new)
{
	while (start->next)
		start = start->next;
	start->next = new;
}

t_spot			*ft_get_spot(int fd)
{
	char	*line;
	int		ret;
	t_color	*color;
	t_vec	*pos;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (ft_strstr(line, "pos:"))
			pos = ft_vector(fd);
		if (ft_strstr(line, "color:"))
			color = ft_color(fd);
	}
	if (ret == -1)
		exit(-1);
	return (ft_new_spot(color, pos));
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
