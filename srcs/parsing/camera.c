/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:57:26 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/07 15:56:56 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void		ft_get_camera(int fd, t_env *env)
{
	char		*line;
	int 		ret;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "-------"))
	{
		if (ft_strstr(line, "pos:"))
			env->cam_pos = ft_vector(fd);
		if (ft_strstr(line, "dir:"))
			env->cam_dir = ft_vector(fd);
		free(line);
	}
	free(line);
}
