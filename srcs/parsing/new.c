/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 16:19:05 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/24 17:22:37 by qduperon         ###   ########.fr       */
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
}

t_obj		*ft_new_obj5(t_vec pos, t_vec rot, t_color col)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->size = 0;
	obj->col = col;
	obj->pos = pos;
	obj->rot = rot;
	obj->type = 4;
}
