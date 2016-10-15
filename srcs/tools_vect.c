/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_vect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:58:20 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/15 17:24:26 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec		*ft_neg(t_vec *v)
{
	t_vec	*v2;

	v2 = NULL;
	new_vec(v->x * -1, v->y * -1,  v->z * -1);
	return (v2);
}

t_vec		*ft_norm(t_vec *v)
{
	double m;
	t_vec *v2;

	m = ft_magnitude(v);
	v2 = new_vec(v->x / m, v->y / m, v->z /m);
	return (v2);
}

double		ft_magnitude(t_vec *v)
{
	return (sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}
