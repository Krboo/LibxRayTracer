/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:21:52 by pmartine          #+#    #+#             */
/*   Updated: 2016/12/20 20:47:04 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		ft_keyhook(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	if (keycode == PAGEUP)
		env->spots->pos.z += 10;
	if (keycode == PAGEDOWN)
		env->spots->pos.z -= 10;
	if (keycode == UP)
		env->spots->pos.y += 10;
	if (keycode == DOWN)
		env->spots->pos.y -= 10;
	if (keycode == DEZOOM)
		env->cam_pos.z -= 10;
	if (keycode == ZOOM)
		env->cam_pos.z += 10;
	if (keycode == RIGHT)
		env->spots->pos.x += 10;
	if (keycode == LEFT)
		env->spots->pos.x -= 10;
	if (keycode == PRINT)
		putdisplay(env);
	draw(env);
	return (0);
}

int		ft_red_cross(int keycode, t_env *env)
{
	(void)keycode;
	(void)env;
	//mlx_destroy_window(env->mlx, env->win);
	exit(0);
}
