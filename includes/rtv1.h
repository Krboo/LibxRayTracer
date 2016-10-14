/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:37:15 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/13 19:58:17 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include "defines.h"

typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
}					t_vec;

typedef struct		s_color
{
	float			r;
	float			g;
	float			b;
}					t_color;

typedef	struct		s_ray
{
	t_vec			pos;
	t_vec			dir;
}					t_ray;

typedef struct		s_obj
{
	int				type;
	float			size;
	int				radius;
	float			d;
	int				color;
	t_vec			dir;
	t_vec			pos;
	t_vec			scale;
}					t_obj;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				display;
	int				endian;
	int				bpp;
	int				s_line;
	t_vec				l;
	char			*data;
	t_obj			obj;
}					t_env;

int		draw(t_env env);
int		ft_error(char *str);
void	display(t_env *e);
int		ft_keyhook(int keycode, t_env *env);
int		ft_red_cross(int keycode, t_env *env);

//VECTORS
t_vec	sub_vect(t_vec *v1, t_vec *v2);
t_vec	add_vect(t_vec *v1, t_vec *v2);
t_vec	mult_vect(t_vec *v1, float fact);
t_vec	norm_vect(t_vec *v1);
float	scale(t_vec *v1, t_vec *v2);
t_vec	init_vec(int x, int y, int z);
//OBJECTS
void	ft_init_sphere(t_obj *s);
void	ft_init_plan(t_obj *s);
int		ft_sphere(t_obj *s, t_ray *r, float *d);
int		ft_plan(t_obj *s, t_ray *r, float *d);
void	ft_init_light(t_obj *l);

#endif
