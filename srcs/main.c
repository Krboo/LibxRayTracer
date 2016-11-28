/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:42:19 by pmartine          #+#    #+#             */
/*   Updated: 2016/11/28 14:04:56 by pmartine         ###   ########.fr       */
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
	t_obj	*node;
	char	*str;

	str = NULL;
	node = e->obj;
	while (node->type != 1)
		node = node->next;
	mlx_string_put(e->mlx, e->win, 5, 15, RED, "light x: ");
	mlx_string_put(e->mlx, e->win, 5, 30, RED, "light y: ");
	mlx_string_put(e->mlx, e->win, 5, 45, RED, "light z: ");
	mlx_string_put(e->mlx, e->win, 95, 15, RED, str = ft_itoa(e->spots->pos.x));
	free(str);
	mlx_string_put(e->mlx, e->win, 95, 30, RED, str = ft_itoa(e->spots->pos.y));
	free(str);
	mlx_string_put(e->mlx, e->win, 95, 45, RED, str = ft_itoa(e->spots->pos.z));
	free(str);
	mlx_string_put(e->mlx, e->win, 5, 100, RED, "sphere x: ");
	mlx_string_put(e->mlx, e->win, 5, 115, RED, "sphere y: ");
	mlx_string_put(e->mlx, e->win, 5, 130, RED, "sphere z: ");
	mlx_string_put(e->mlx, e->win, 5, 145, RED, "sphere r: ");
	mlx_string_put(e->mlx, e->win, 95, 100, RED, str = ft_itoa(node->pos.x));
	free(str);
	mlx_string_put(e->mlx, e->win, 95, 115, RED, str = ft_itoa(node->pos.y));
	free(str);
	mlx_string_put(e->mlx, e->win, 95, 130, RED, str = ft_itoa(node->pos.z));
	free(str);
	mlx_string_put(e->mlx, e->win, 95, 145, RED, str = ft_itoa(node->size));
	free(str);
	mlx_string_put(e->mlx, e->win, 5, 175, RED, "cam_pos z: ");
	mlx_string_put(e->mlx, e->win, 105, 175, RED, str = ft_itoa(e->cam_pos.z));
	free(str);
}

static t_env *init_env(char *map)
{
	t_env	*e;
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W, H, "Rtv1");
	e->img = (t_img *)malloc(sizeof(t_img));
	e->img->img = mlx_new_image(e->mlx, W, H);
	e->img->data = mlx_get_data_addr(e->img->img, &e->img->bpp, &e->img->s_line, &e->img->endian);
	e->obj = NULL;
	e->spots = NULL;
	ft_init_scene(map, e);
	ft_putendl("ft_init_scene is OK");
	if (e->spots->next != NULL)
		ft_putendl("multi spots");
	return (e);
}

int		main(int ac,char **av)
{
	t_env	*env;

	if (ac != 2)
		ft_error("Usage : ./RTv1 scene_file (ex: ./RTv1 scene/demo.1)");
	else if ((env = init_env(av[1])) != NULL)
	{
		draw(env);
	//	display(env);
	//	putdisplay(env);
		mlx_hook(env->win, 2, 1L << 0, ft_keyhook, env);
		mlx_hook(env->win, 17, (1L << 17), ft_red_cross, 0);
		mlx_loop(env->mlx);
	}
	return (0);
}
