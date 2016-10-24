/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:37:15 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/24 18:15:28 by pmartine         ###   ########.fr       */
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
	struct s_spots	*next;
}					t_spot;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_obj			*obj;
	t_spots			*spots;
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
void    ft_deleted_vect(t_vec vect);
/*
** parser.c
*/
t_cam	*ft_new_camera(t_vec pos, t_vec dir);
t_scene	*ft_get_scene(void);
t_scene	*ft_init_scene(char *scene);
/*
** objects.c
*/
int		ft_sphere(t_scene *s, t_ray *r, double *d);
int		ft_plan(t_scene *s, t_ray *r, double *d);
int		ft_cylindre(t_scene *s, t_ray *r, double *d);
int		ft_intersections(t_scene *s, double *d);
/*
** camera.c
*/
void	ft_get_camera(int fd, t_env *env);
/*
** clear.c
*/
void	ft_clear_obj(t_obj **start);
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
t_obj				*ft_get_cones(int fd);
/*
** cylindre.c
*/
t_obj				*ft_get_cylind(int fd, t_vec rot);
t_obj				*ft_get_cylinds(int fd);
/*
* new.c
*/
t_obj				*ft_new_obj(double size, t_vec pos, t_vec rot, t_color col);
t_obj				*ft_new_obj2(double size, t_vec pos, t_vec rot, t_color col);
t_obj				*ft_new_obj3(double size, t_vec pos, t_vec rot, t_color col);
t_obj				*ft_new_obj4(double size, t_vec pos, t_vec rot, t_color col);
t_obj				*ft_new_obj5(t_vec pos, t_vec rot, t_color col);
/*
** plan.c
*/
t_obj				*ft_get_plans(int fd);
t_obj				*ft_new_plan(double dis, t_color color, t_vec pos);
/*
** sphere.c
*/
t_obj	            *ft_get_sphere(int fd);
t_obj	            *ft_get_spheres(int fd);
/*
** spot.c
*/
t_obj				*ft_get_spot(int fd, t_vec rot);
t_obj				*ft_get_spots(int fd);
/*
** tools_vect.c
*/
double              ft_magnitude(t_vec v);
t_vec               ft_neg(t_vec v);
t_vec               ft_norm(t_vec v);
#endif
