/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:23:29 by pmartine          #+#    #+#             */
/*   Updated: 2016/12/07 10:23:30 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double		dot_vect(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec		norm_vect(t_vec v)
{
	double	len;
	t_vec	vec;

	len = 1.0 / sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	vec.x = v.x * len;
	vec.y = v.y * len;
	vec.z = v.z * len;
	return (vec);
}

t_vec		cross_vect(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}
