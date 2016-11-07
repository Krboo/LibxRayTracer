/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:00:42 by pmartine          #+#    #+#             */
/*   Updated: 2016/11/07 17:21:36 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		ft_keyhook(int	keycode, t_env *env)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	if (keycode == RIGHT)
		env->spots->pos.x += 2;
	if (keycode == LEFT)
		env->spots->pos.x -= 2;
	if (keycode == UP)
		env->spots->pos.y -= 2;
	if (keycode == DOWN)
		env->spots->pos.y += 2;
	if (keycode == DEZOOM)
		env->cam_pos.z -= 10;
	if (keycode == ZOOM)
		env->cam_pos.z += 10;
	draw(env);
	display(env);
//	putdisplay(env);
	return (0);
}

int	ft_red_cross(int keycode, t_env *env)
{
	(void)keycode;
	(void)env;
	exit (0);
}
