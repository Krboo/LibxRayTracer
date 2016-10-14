/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_vect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:58:20 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/14 15:41:09 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

t_pos		*ft_neg(t_pos *v)
{
	t_pos	*v2;

	ft_new_vector(v->x * -1, v->y * -1,  v->z * -1);
	return (v2);
}

t_pos		*ft_norm(t_pos *v)
{
	double m;
	t_pos *v2;

	m = ft_magnitude(v);
	v2 = ft_new_vector(v->x / m, v->y / m, v->z /m);
	return (v2);
}

double		ft_magnitude(t_pos *v)
{
	return (sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}
