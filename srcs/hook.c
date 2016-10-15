/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:00:42 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/15 14:46:43 by pmartine         ###   ########.fr       */
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
		env->l->x += 5;
	if (keycode == LEFT)
		env->l->x -= 5;
	if (keycode == UP)
		env->l->y -= 5;
	if (keycode == DOWN)
		env->l->y += 5;
	if (keycode == DEZOOM)
		env->l->z += 5;
	if (keycode == ZOOM)
		env->l->z -= 5;
	draw((*env));
	display(env);
	return (0);
}

int	ft_red_cross(int keycode, t_env *env)
{
	(void)keycode;
	(void)env;
	exit (0);
}
