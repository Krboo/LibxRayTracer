/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:14:50 by pmartine          #+#    #+#             */
/*   Updated: 2016/12/07 09:16:57 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void		ft_put_pixel(t_env *env, int x, int y, int color)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = x * (env->img->bpp / 8) + y * (env->img->s_line);
	while (i < (env->img->bpp / 8))
	{
		env->img->data[p + i] = color;
		color >>= 8;
		i++;
	}
}

static void		create_ray(t_env *e, int x, int y)
{
	t_vec	v1;
	t_vec	v2;
	t_vec	v3;
	double	u;
	double	v;

	u = (W - (double)x * 2.0) / H;
	v = (H - (double)y * 2.0) / W;
	v1 = sub_vect(e->cam_dir, e->cam_pos);
	v1 = norm_vect(v1);
	v2 = cross_vect(v1, (t_vec){0.0, 1.0, 0.0});
	v2 = norm_vect(v2);
	v3 = cross_vect(v2, v1);
	e->ray_dir = (t_vec){u * v2.x + v * v3.x + FOV * v1.x, u * v2.y + v * v3.y \
		+ FOV * v1.y, u * v2.z + v * v3.z + FOV * v1.z};
	e->ray_dir = norm_vect(e->ray_dir);
	e->ray_pos = e->cam_pos;
}

static int		lambert_rgb(int r, int g, int b, double lambert)
{
	r *= lambert;
	g *= lambert;
	b *= lambert;
	r = min_max(r, 0, 255);
	g = min_max(g, 0, 255);
	b = min_max(b, 0, 255);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void			trace(t_env *env, t_obj *node, int x, int y)
{
	t_obj	*tmp;
	double	lambert;
	t_spot	*first;

	lambert = 0;
	tmp = NULL;
	first = env->spots;
	env->d = 20000.0;
	create_ray(env, x, y);
	tmp = ft_intersection(env, node);
	if (tmp != NULL)
	{
		if (tmp->type == 5)
			lambert = 1.0;
		else
			while (env->spots)
			{
				lambert += calc_lamb(env, tmp);
				env->spots = env->spots->next;
			}
		ft_put_pixel(env, x, y, \
				lambert_rgb(tmp->col.r, tmp->col.g, tmp->col.b, lambert));
	}
	env->spots = first;
}

int				draw(t_env *env)
{
	int		x;
	int		y;
	t_obj	*node;

	node = env->obj;
	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
			ft_put_pixel(env, x, y, BLACK);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
			trace(env, node, x, y);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	return (0);
}
