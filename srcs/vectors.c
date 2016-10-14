/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:57:25 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/07 18:14:30 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/rtv1.h"

t_vec	add_vect(t_vec	*v1, t_vec	*v2)
{
	t_vec	v3;

	v3.x = v1->x + v2->x;
	v3.y = v1->y + v2->y;
	v3.z = v1->z + v2->z;
	return (v3);
}

t_vec	sub_vect(t_vec *v1, t_vec *v2)
{
	t_vec	v3;

	v3.x = v1->x - v2->x;
	v3.y = v1->y - v2->y;
	v3.z = v1->z - v2->z;
	return (v3);
}

t_vec	mult_vect(t_vec	*v1, float fact)
{
	t_vec	v2;
	v2.x = v1->x * fact;
	v2.y = v1->y * fact;
	v2.z = v1->z * fact;
	return (v2);
}

float	scale(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec	norm_vect(t_vec *v1)
{
	t_vec	v2;
	float	len;

	len = sqrtf((v1->x * v1->x) + (v1->y * v1->y) + (v1->z * v1->z));
	v2.x = v1->x / len;
	v2.y = v1->y / len;
	v2.z = v1->z / len;
	return (v2);
}

t_vec	cross_vec(t_vec v1, t_vec v2)
{
	t_vec		result;

	result.x = v1.y * v2.z - v2.y - v1.z;
	result.y = v1.z * v2.x - v2.z * v1.x;
	result.z = v1.x * v2.y - v2.x * v1.y;
	return (result);
}
