/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:21:52 by pmartine          #+#    #+#             */
/*   Updated: 2016/12/22 16:29:51 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static int	ft_keyhook2(int keycode, t_env *env)
{
	if (keycode == ZOOM)
		env->spots->pos.z += 10;
	else if (keycode == DEZOOM)
		env->spots->pos.z -= 10;
	else if (keycode == KEY8)
		env->spots->pos.y += 10;
	else if (keycode == KEY2)
		env->spots->pos.y -= 10;
	else if (keycode == KEY4)
		env->spots->pos.x -= 10;
	else if (keycode == KEY6)
		env->spots->pos.x += 10;
	else if (keycode == PRINT)
		putdisplay(env);
	return (0);
}

int			ft_keyhook(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	if (keycode == PAGEUP)
		env->cam_pos.z += 30;
	else if (keycode == PAGEDOWN)
		env->cam_pos.z -= 30;
	else if (keycode == UP)
		env->cam_pos.y += 30;
	else if (keycode == DOWN)
		env->cam_pos.y -= 30;
	else if (keycode == RIGHT)
		env->cam_pos.x += 30;
	else if (keycode == LEFT)
		env->cam_pos.x -= 30;
	else
		ft_keyhook2(keycode, env);
	draw(env);
	return (0);
}

int			ft_red_cross(int keycode, t_env *env)
{
	(void)keycode;
	(void)env;
	exit(0);
}
