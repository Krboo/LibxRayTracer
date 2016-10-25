/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:37:15 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/25 16:04:34 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include "defines.h"
# include <fcntl.h>

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef	struct		s_img
{
	char			*data;
	int				bpp;
	int				endian;
	int				s_line;
	void			*img;
}					t_img;

typedef struct		s_obj
{
	int				type;
	double			size;
	t_color			col;
	t_vec			pos;
	t_vec			rot;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_spot
{
	t_color			col;
	t_vec			pos;
	double			size;
	struct s_spot	*next;
}					t_spot;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_obj			*obj;
	t_spot			*spots;
	t_vec			cam_pos;
	t_vec			cam_dir;
	t_vec			ray_dir;
	t_vec			ray_pos;
}					t_env;

int		draw(t_env *env);
int		ft_error(char *str);
void	display(t_env *e);
int		ft_keyhook(int keycode, t_env *env);
int		ft_red_cross(int keycode, t_env *env);
/*
** vectors.c
*/
void	ft_deleted_vect(t_vec vect);
t_vec	sub_vect(t_vec v1, t_vec v2);
t_vec	scale_vect(t_vec v1, double fact);
t_vec	add_vect(t_vec v1, t_vec v2);
t_vec	norm_vect(t_vec v);
double	dot_vect(t_vec v1, t_vec v2);
t_vec	new_vec(double x, double y, double z);
t_vec	ft_vector(int fd);
t_vec	cross_vect(t_vec v1, t_vec v2);
/*
** init.c
*/
void	ft_add_obj(t_obj *start, t_obj *new);
void	ft_add_spot(t_spot *start, t_spot *new);
void	ft_init_scene(char *scene, t_env *env);
/*
** spots.c
*/
t_spot	*ft_get_spot(int fd);
t_spot	*ft_get_spots(int fd);
/*
** objects.c
*/
int		ft_sphere(t_obj *obj, t_env *e, double *d);
//int		ft_plan(t_scene *s, t_ray *r, double *d);
//int		ft_cylindre(t_scene *s, t_ray *r, double *d);
//int		ft_intersections(t_scene *s, double *d);
/*
** camera.c
*/
void	ft_get_camera(int fd, t_env *env);
/*
** clear.c
*/
void	ft_clear_obj(t_obj **start);
void	ft_clear_spot(t_spot **start);
/*
** color.c
*/
t_color				ft_color(int fd);
t_color				ft_new_color(double r, double g, double b);
void				ft_deleted_color(t_color color);
/*
** cone.c
*/
t_obj				*ft_get_cone(int fd, t_vec rot);
void				ft_get_cones(int fd, t_env *env);
/*
** cylindre.c
*/
t_obj				*ft_get_cylind(int fd, t_vec rot);
void				ft_get_cylinds(int fd, t_env *env);
/*
** init.c
*/
void				ft_add_obj(t_obj *start, t_obj *new);
void				ft_add_spot(t_spot *start, t_spot *new);
void				ft_init_scene(char *scene, t_env *env);
/*
* new.c
*/
t_obj				*ft_new_obj(double size, t_vec pos, t_vec rot, t_color col);
t_obj				*ft_new_obj2(double size, t_vec pos, t_vec rot, t_color col);
t_obj				*ft_new_obj3(double size, t_vec pos, t_vec rot, t_color col);
t_obj				*ft_new_obj4(double size, t_vec pos, t_vec rot, t_color col);
t_spot				*ft_new_spot(double size, t_vec pos, t_color col);
/*
** plan.c
*/
t_obj				*ft_get_plan(int fd, t_vec rot);
void				ft_get_plans(int fd, t_env *env);
/*
** sphere.c
*/
t_obj	            *ft_get_sphere(int fd, t_vec rot);
void	            ft_get_spheres(int fd, t_env *env);
#endif
