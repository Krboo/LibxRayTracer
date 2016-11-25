/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:14:50 by pmartine          #+#    #+#             */
/*   Updated: 2016/11/21 16:49:42 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/rtv1.h"

static void	ft_put_pixel(t_env	*env, int x, int y, int color)
{
	int		i;
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

static void create_ray(t_env *e, int x, int y)
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
	e->ray_dir = (t_vec){u * v2.x + v * v3.x + FOV * v1.x, u * v2.y + v * v3.y + FOV * v1.y, u *v2.z + v * v3.z + FOV * v1.z};
	e->ray_dir = norm_vect(e->ray_dir);
	e->ray_pos = e->cam_pos;
}

static int	lambert_rgb(int r, int g, int b, double lambert)
{
	r *= lambert;
	g *= lambert;
	b *= lambert;
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

/*static double	calc_lamb(t_env	*env, t_vec	pos)
{
	t_vec	vec;
	t_vec	cam;
	t_vec	yo;
	double	lambert;

	cam = scale_vect(env->ray_dir, env->d);
	cam = add_vect(env->ray_pos, cam);
	yo = sub_vect(cam, env->spots->pos);
	yo = norm_vect(yo);
	vec = sub_vect(pos, cam);
	vec = norm_vect(vec);
	lambert = dot_vect(yo, vec);
	if (lambert < 0.2)
		lambert = 0.2;
	if (lambert < EPSI)
		lambert = 0;
	return (lambert);
}
*/

static double	calc_lamb(t_env	*env, t_obj	*obj)
{
	t_vec	dist;
	t_vec	cam;
	t_vec	norm;
	double	lambert;

	cam = add_vect(env->ray_pos, scale_vect(env->ray_dir, env->d));
	norm = normale(obj ,env ,cam);
	dist = sub_vect(env->spots->pos, cam);
	dist = norm_vect(dist);
	lambert = 0;
	lambert += dot_vect(dist, norm);
	if (lambert < EPSI)
		lambert = 0;
	if (lambert > 1.0)
		lambert = 1;
	return (lambert);
}

void	trace(t_env *env, t_obj *node, int x, int y)
{
	t_obj	*tmp;
	double	lambert;
	t_spot	*first;

	lambert = 0;
	first = env->spots;
	tmp = NULL;
	env->d = 20000.0;
	create_ray(env, x , y);
	tmp = ft_intersection(env, node);
	if (tmp != NULL)
	{
		while (env->spots)
		{
						lambert = lambert  > calc_lamb(env, tmp) ? lambert : calc_lamb(env, tmp);
						lambert = lambert > 1 ? 1.0 : lambert;
						lambert = lambert < 0.0 ? 0.0 : lambert;
						env->spots = env->spots->next;
		}
		ft_put_pixel(env, x, y, lambert_rgb(tmp->col.r,tmp->col.g, tmp->col.b, lambert));
	}
	env->spots = first;
}



int	draw(t_env	*env)
{
	int		x;
	int		y;
	t_obj 		*node;

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
