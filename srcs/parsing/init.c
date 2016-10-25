/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 13:44:17 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/25 16:02:53 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void	ft_add_obj(t_obj *start, t_obj *new)
{
	while (start->next)
		start = start->next;
	start->next = new;
}

void	ft_add_spot(t_spot *start, t_spot *new)
{
	while (start->next)
		start = start->next;
	start->next = new;
}
void	ft_init_scene(char *scene, t_env *env)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(scene, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strstr(line, "camera:"))
			ft_get_camera(fd, env);
		if (ft_strstr(line, "cone:"))
			ft_get_cones(fd, env);
		if (ft_strstr(line, "cylindre:"))
			ft_get_cylinds(fd, env);
		if (ft_strstr(line, "plan:"))
			ft_get_plans(fd, env);
		if (ft_strstr(line, "sphere:"))
			ft_get_spheres(fd, env);
		if (ft_strstr(line, "spot:"))
			env->spots = ft_get_spots(fd);
	}
	if (ret == -1)
		exit (-1);
}
