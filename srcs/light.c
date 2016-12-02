/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:16:04 by pmartine          #+#    #+#             */
/*   Updated: 2016/12/02 17:29:32 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double      min_max(double numb, double min, double max)
{
	if (numb < min)
		numb = min;
	if (numb > max)
		numb = max;
	return (numb);
}

/*double	calc_spec(t_env *env, t_obj *obj)
{
	float	spec;
	float	tmp;
	t_vec	ref;

	spec = 0.0;
	ref = ft_vectorscale(&mlx->norm, (2.0 * ft_vectordot(&mlx->norm, &dist)));
	ref = ft_vectorsub(&dist, &ref);
	if ((tmp = ft_vectordot(&ref, &mlx->ray_dir)) > 0.0)
	{
		spec = pow(tmp, 30.0) * 1.0;
		spec = ft_clamp(spec, 0.0, 1.0);
	}
	return (spec);
}
*/
double   calc_lamb(t_env *env, t_obj *obj)
{
	t_vec   dist;
	t_vec   cam;
	t_vec   norm;
	double  lambert;
	double	spec;

	cam = add_vect(env->ray_pos, scale_vect(env->ray_dir, env->d));
	norm = normale(obj ,env ,cam);
	dist = sub_vect(env->spots->pos, cam);
	dist = norm_vect(dist);
	lambert = 0;
	lambert += dot_vect(dist, norm) * 0.9;
	spec = 0.08;
	lambert = min_max(lambert + spec, 0.15, 1.0) ;
	return (lambert);
}
