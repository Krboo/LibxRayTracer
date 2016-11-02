/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:37:59 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/02 17:56:41 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		putcam(t_env *env)
{
	ft_putendl("camera:");
	ft_putendl("pos:");
	ft_putstr("x:");
	ft_putdouble(env->cam_pos.x, 4);
	ft_putstr(" y:");
	ft_putdouble(env->cam_pos.y, 4);
	ft_putstr(" z:");
	ft_putdouble(env->cam_pos.z, 4);
	ft_putchar('\n');
	ft_putendl("dir:");
	ft_putstr("x:");
	ft_putdouble(env->cam_dir.x, 4);
	ft_putstr(" y:");
	ft_putdouble(env->cam_dir.y, 4);
	ft_putstr(" z:");
	ft_putdouble(env->cam_dir.z, 4);
	ft_putchar('\n');
}

void		putlight(t_env *env)
{
	if (env->spots)
	{
		while (env->spots->next)
		{
			ft_putendl("lights:");
			ft_putendl("pos:");
			ft_putstr("x:");
			ft_putdouble(env->spots->pos.x, 4);
			ft_putstr(" y:");
			ft_putdouble(env->spots->pos.y, 4);
			ft_putstr(" z:");
			ft_putdouble(env->spots->pos.z, 4);
			ft_putchar('\n');
			env->spots = env->spots->next;
		}
		ft_putendl("lights:");
		ft_putendl("pos:");
		ft_putstr("x:");
		ft_putdouble(env->spots->pos.x, 4);
		ft_putstr(" y:");
		ft_putdouble(env->spots->pos.y, 4);
		ft_putstr(" z:");
		ft_putdouble(env->spots->pos.z, 4);
		ft_putchar('\n');
	}
}

char		*type_obj(t_obj *obj)
{
	if (obj->type == 0)
		return ("plan");
	if (obj->type == 1)
		return ("sphere");
	if (obj->type == 2)
		return ("cone");
	if (obj->type == 3)
		return ("cylindre");
	return (NULL);
}

void		putobj2(t_obj *obj)
{
	ft_putendl(type_obj(obj));
	ft_putendl("pos:");
	ft_putstr("x:");
	ft_putdouble(obj->pos.x, 4);
	ft_putstr(" y:");
	ft_putdouble(obj->pos.y, 4);
	ft_putstr(" z:");
	ft_putdouble(obj->pos.z, 4);
	ft_putchar('\n');
	ft_putendl("rot:");
	ft_putstr("x:");
	ft_putdouble(obj->rot.x, 4);
	ft_putstr(" y:");
	ft_putdouble(obj->rot.y, 4);
	ft_putstr(" z:");
	ft_putdouble(obj->rot.z, 4);
	ft_putchar('\n');
}

void		putobj(t_env *env)
{
	if (env->obj)
	{
		env->obj = env->obj->next;
		while (env->obj->next)
		{
			putobj2(env->obj);
			env->obj = env->obj->next;
		}
		putobj2(env->obj);
	}
}
