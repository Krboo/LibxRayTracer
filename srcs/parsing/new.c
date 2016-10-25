/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 16:19:05 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/25 12:16:12 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj		*ft_new_obj(double size, t_vec pos, t_vec rot, t_color col)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->size = size;
	obj->col = col;
	obj->pos = pos;
	obj->rot = rot;
	obj->type = 0;
	return (obj);
}

t_obj		*ft_new_obj2(double size, t_vec pos, t_vec rot, t_color col)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->size = size;
	obj->col = col;
	obj->pos = pos;
	obj->rot = rot;
	obj->type = 1;
	return (obj);
}

t_obj		*ft_new_obj3(double size, t_vec pos, t_vec rot, t_color col)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->size = size;
	obj->col = col;
	obj->pos = pos;
	obj->rot = rot;
	obj->type = 2;
	return (obj);
}

t_obj		*ft_new_obj4(double size, t_vec pos, t_vec rot, t_color col)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->size = size;
	obj->col = col;
	obj->pos = pos;
	obj->rot = rot;
	obj->type = 3;
	return (obj);
}

t_spot		*ft_new_spot(double size, t_vec pos, t_color col)
{
	t_spot	*spot;

	if (!(spot = (t_spot *)malloc(sizeof(t_spot))))
		return (NULL);
	spot->size = size;
	spot->col = col;
	spot->pos = pos;
	return (spot);
}
