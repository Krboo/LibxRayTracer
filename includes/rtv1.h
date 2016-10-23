/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:37:15 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/23 16:00:23 by pmartine         ###   ########.fr       */
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

//typedef	struct		s_img
//{
//	char			*data;
//	int				bpp;
//	int				endian;
//	int				sl;
//	void			*img;
//}					t_img

typedef struct		s_cam
{
	t_vec			*pos;
	t_vec			*dir;
}					t_cam;

typedef struct		s_cone
{
	double			alpha;
	t_color			*color;
	t_vec			*pos;
	struct s_cone	*next;
}					t_cone;

typedef struct		s_cylind
{
	double			radius;
	t_color			*color;
	t_vec			*pos;
	struct s_cylind	*next;
}					t_cylind;

typedef struct		s_plan
{
	double			dis;
	t_color			*color;
	t_vec			*pos;
	struct s_plan	*next;
}					t_plan;

typedef struct		s_sphere
{
	double			radius;
	t_color			*color;
	t_vec			*pos;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_spot
{
	t_color			*color;
	t_vec			*pos;
	struct s_spot	*next;
}					t_spot;

typedef	struct		s_ray
{
	t_vec			pos;
	t_vec			dir;
}					t_ray;

typedef struct		s_scene
{
	t_cam			*cam;
	t_cone			*cone;
	t_cylind		*cylind;
	t_plan			*plan;
	t_sphere		*sphere;
	t_spot			*spot;
	t_ray			*ray;
}					t_scene;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
//	t_img			img;
	void			*img;
	t_scene			*s;
	int				endian;
	int				bpp;
	int				s_line;
	char			*data;
}					t_env;

int		draw(t_env *env);
int		ft_error(char *str);
void	display(t_env *e);
int		ft_keyhook(int keycode, t_env *env);
int		ft_red_cross(int keycode, t_env *env);
/*
** vectors.c
*/
void	ft_deleted_vect(t_vec *vect);
t_vec	sub_vect(t_vec *v1, t_vec *v2);
t_vec	scale_vect(t_vec *v1, double fact);
t_vec	add_vect(t_vec *v1, t_vec *v2);
void	norm_vect(t_vec *v);
double	dot_vect(t_vec *v1, t_vec *v2);
t_vec	*new_vec(double x, double y, double z);
t_vec	*ft_vector(int fd);
t_vec	cross_vect(t_vec *v1, t_vec *v2);
void                ft_deleted_vect(t_vec *vect);
/*
** parser.c
*/
t_cam	*ft_new_camera(t_vec *pos, t_vec *dir);
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
t_cam	*ft_get_camera(int fd);
/*
** clear.c
*/
void	ft_deleted_cone(t_cone **start);
void	ft_deleted_cylindre(t_cylind **start);
void	ft_deleted_plan(t_plan **start);
void	ft_deleted_sphere(t_sphere **start);
void	ft_deleted_spot(t_spot **start);
/*
** color.c
*/
t_color	*ft_color(int fd);
t_color	*ft_new_color(double r, double g, double b);
void	ft_deleted_color(t_color *color);
/*
** cone.c
*/
t_cone	*ft_get_cone(int fd);
t_cone	*ft_get_cones(int fd);
t_cone	*ft_new_cone(double alpha, t_color *color, t_vec *pos);
void	ft_add_cone(t_cone *start, t_cone *new);
/*
** cylindre.c
*/
t_cylind	*ft_get_cylind(int fd);
t_cylind	*ft_get_cylinds(int fd);
t_cylind	*ft_new_cylind(double radius, t_color *color, t_vec *pos);
void		ft_add_cylind(t_cylind *start, t_cylind *new);
/*
** plan.c
*/
t_plan              *ft_get_plans(int fd);
t_plan              *ft_new_plan(double dis, t_color *color, t_vec *pos);
void                ft_add_plan(t_plan *start, t_plan *new);
/*
** sphere.c
*/
t_sphere            *ft_get_sphere(int fd);
t_sphere            *ft_get_spheres(int fd);
t_sphere            *ft_new_sphere(double radius, t_color *color, t_vec *pos);
void                ft_add_sphere(t_sphere *start, t_sphere *new);
/*
** spot.c
*/
t_spot              *ft_get_spot(int fd);
t_spot              *ft_get_spots(int fd);
t_spot              *ft_new_spot(t_color *color, t_vec *pos);
void                ft_add_spot(t_spot *start, t_spot *new);
/*
** tools_vect.c
*/
double              ft_magnitude(t_vec *v);
t_vec               *ft_neg(t_vec *v);
t_vec               *ft_norm(t_vec *v);
#endif
