/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:42:19 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/15 14:51:50 by pmartine         ###   ########.fr       */
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
		mlx_string_put(e->mlx, e->win, 95, 0, RED, ft_itoa(e->l->x));
		mlx_string_put(e->mlx, e->win, 95, 15, RED, ft_itoa(e->l->y));
		mlx_string_put(e->mlx, e->win, 95, 30, RED, ft_itoa(e->l->z));
		mlx_string_put(e->mlx, e->win, 5, 100, RED, "sphere x: ");
		mlx_string_put(e->mlx, e->win, 5, 115, RED, "sphere y: ");
		mlx_string_put(e->mlx, e->win, 5, 130, RED, "sphere z: ");
		mlx_string_put(e->mlx, e->win, 5, 145, RED, "sphere r: ");
		mlx_string_put(e->mlx, e->win, 95, 100, RED, ft_itoa(e->obj.pos.x));
		mlx_string_put(e->mlx, e->win, 95, 115, RED, ft_itoa(e->obj.pos.y));
		mlx_string_put(e->mlx, e->win, 95, 130, RED, ft_itoa(e->obj.pos.z));
		mlx_string_put(e->mlx, e->win, 95, 145, RED, ft_itoa(e->obj.radius));
}

static t_env	init_env(char *scene)
{
	t_env	e;

	(void)scene;
	e.l = new_vec(0,0,0);
	ft_init_sphere(&e.obj);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, W, H, "Rtv1");
	e.img = mlx_new_image(e.mlx, W, H);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.s_line, &e.endian);
	e.display = 1;
	return (e);
}

int		main(int ac,char **av)
{
	t_env	env;

	if (ac != 2)
		ft_error("Merci bien de rentrer un argument");
	env = init_env(av[1]);
	draw(env);
	display(&env);
	mlx_hook(env.win, 2, 1L << 0, ft_keyhook, &env);
	mlx_hook(env.win, 17, (1L << 17), ft_red_cross, 0);
	mlx_loop(env.mlx);
	return (0);
}
