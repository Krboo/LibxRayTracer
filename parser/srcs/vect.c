/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:27:25 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/14 15:30:33 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

t_pos		*ft_new_vector(double x, double y, double z)
{
	t_pos	*vect;

	if(!(vect = (t_pos *)malloc(sizeof(t_pos))))
		return (NULL);
	vect->x = x;
	vect->y = y;
	vect->z = z;
	return (vect);
}

t_pos		*ft_vector(int fd)
{
	double	x;
	double	y;
	double	z;
	char	*line;

	if (get_next_line(fd, &line) < 1)
		exit(-1);
	x = ft_atodouble(&line);
	y = ft_atodouble(&line);
	z = ft_atodouble(&line);
	return (ft_new_vector(x, y, z));
}
void		ft_deleted_vect(t_pos *vect)
{
	free(vect);
}
