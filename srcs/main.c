/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:42:19 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/24 12:03:28 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	display(t_env	*e)
{
	mlx_string_put(e->mlx, e->win, 5, 0, RED, "light x: ");
	mlx_string_put(e->mlx, e->win, 5, 15, RED, "light y: ");
	mlx_string_put(e->mlx, e->win, 5, 30, RED, "light z: ");
	mlx_string_put(e->mlx, e->win, 95, 0, RED, ft_itoa(e->s->spot->pos->x));
	mlx_string_put(e->mlx, e->win, 95, 15, RED, ft_itoa(e->s->spot->pos->y));
	mlx_string_put(e->mlx, e->win, 95, 30, RED, ft_itoa(e->s->spot->pos->z));
	mlx_string_put(e->mlx, e->win, 5, 100, RED, "sphere x: ");
	mlx_string_put(e->mlx, e->win, 5, 115, RED, "sphere y: ");
	mlx_string_put(e->mlx, e->win, 5, 130, RED, "sphere z: ");
	mlx_string_put(e->mlx, e->win, 5, 145, RED, "sphere r: ");
	mlx_string_put(e->mlx, e->win, 95, 100, RED, ft_itoa(e->s->sphere->pos->x));
	mlx_string_put(e->mlx, e->win, 95, 115, RED, ft_itoa(e->s->sphere->pos->y));
	mlx_string_put(e->mlx, e->win, 95, 130, RED, ft_itoa(e->s->sphere->pos->z));
	mlx_string_put(e->mlx, e->win, 95, 145, RED, ft_itoa(e->s->sphere->radius));
}

static t_env	*init_env(char *map)
{
	t_env	*e;
	if (!(e = (t_env *)malloc(sizeof(t_env *))))
		return (NULL);
	e->s = ft_init_scene(map);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W, H, "Rtv1");
	e->img = mlx_new_image(e->mlx, W, H);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->s_line, &e->endian);
	return (e);
}

int		main(int ac,char **av)
{
	t_env	*env;

	if (ac != 2)
		ft_error("Usage : ./RTv1 scene_file (ex: ./RTv1 scene/demo.1)");
	env = init_env(av[1]);
	draw(env);
	display(env);
	mlx_hook(env->win, 2, 1L << 0, ft_keyhook, env);
	mlx_hook(env->win, 17, (1L << 17), ft_red_cross, 0);
	mlx_loop(env->mlx);
	return (0);
}
