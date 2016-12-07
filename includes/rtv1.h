/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:28:26 by pmartine          #+#    #+#             */
/*   Updated: 2016/12/07 10:28:28 by pmartine         ###   ########.fr       */
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

typedef	struct		s_calc
{
	t_vec			v1;
	t_vec			v2;
	t_vec			v3;
}					t_calc;

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
	double			d;
	t_img			*img;
	t_obj			*obj;
	t_spot			*spots;
	t_vec			cam_pos;
	t_vec			cam_dir;
	t_vec			ray_dir;
	t_vec			ray_pos;
	double			dist;
}					t_env;

int					draw(t_env *env);
t_vec				normale(t_obj *obj, t_env *env, t_vec cam);
void				trace(t_env *env, t_obj *node, int x, int y);
int					ft_error(char *str);
void				display(t_env *e);
int					ft_keyhook(int keycode, t_env *env);
int					ft_red_cross(int keycode, t_env *env);
/*
** vectors.c
*/
void				ft_deleted_vect(t_vec vect);
t_vec				sub_vect(t_vec v1, t_vec v2);
t_vec				scale_vect(t_vec v1, double fact);
t_vec				add_vect(t_vec v1, t_vec v2);
t_vec				norm_vect(t_vec v);
double				dot_vect(t_vec v1, t_vec v2);
t_vec				new_vec(double x, double y, double z);
t_vec				ft_vector(char *line);
t_vec				cross_vect(t_vec v1, t_vec v2);
/*
** camera.c
*/
void				ft_get_camera(char **line, t_env *env, int i);
/*
** clear.c
*/
void				ft_clear_obj(t_obj **start);
void				ft_clear_spot(t_spot **start);
/*
** color.c
*/
t_color				ft_color(char *line);
t_color				ft_new_color(double r, double g, double b);
void				ft_deleted_color(t_color color);
/*
** cone.c
*/
t_obj				*ft_get_cone(char **line, int i);
t_obj				*ft_get_cones(char **line, t_env *env, int i);
/*
** cylindre.c
*/
t_obj				*ft_get_cylind(char **line, int i);
t_obj				*ft_get_cylinds(char **line, t_env *env, int i);
/*
** display.c
*/
char				*type_obj(t_obj *obj);
void				putcam(t_env *env);
void				putlight(t_env *env);
void				putobj(t_env *env);
void				putobj2(t_obj *obj);
/*
** init.c
*/
void				ft_add_obj(t_obj *start, t_obj *new);
void				ft_add_spot(t_spot *start, t_spot *new);
void				ft_init_scene(char *scene, t_env *env);
/*
** new.c
*/
t_obj				*ft_new_obj(double size, t_vec pos, t_vec rot, t_color c);
t_obj				*ft_new_obj2(double size, t_vec pos, t_vec rot, t_color c);
t_obj				*ft_new_obj3(double size, t_vec pos, t_vec rot, t_color c);
t_obj				*ft_new_obj4(double size, t_vec pos, t_vec rot, t_color c);
t_spot				*ft_new_spot(double size, t_vec pos, t_color c);
/*
** objects.c
*/
t_obj				*ft_intersection(t_env *e, t_obj *node);
double				ft_plan(t_obj *obj, t_env *e);
double				ft_sphere(t_obj *obj, t_env *e);
double				ft_cylindre(t_obj *obj, t_env *e);
double				ft_cone(t_obj *obj, t_env *e);
/*
** plan.c
*/
t_obj				*ft_get_plan(char **line, int i);
t_obj				*ft_get_plans(char **line, t_env *env, int i);
/*
** sphere.c
*/
t_obj				*ft_get_sphere(char **line, int i);
t_obj				*ft_get_spheres(char **line, t_env *env, int i);
/*
** spots.c
*/
t_spot				*ft_get_spot(char **line, int i);
t_spot				*ft_get_spots(char **line, t_env *env, int i);
/*
** tools.c
*/
char				**ft_files(char *scene, char **file);
double				ft_data(char *line);
int					ft_countline(char *scene);
void				ft_free_tab(char **tab, int i);
/*
** tools.c
*/
t_obj				*inter_loop(t_obj *node, t_env *e, t_obj *tmp, t_obj lum);
void				putdisplay(t_env *env);
/*
** light.c
*/
double				min_max(double numb, double min, double max);
double				calc_lamb(t_env *env, t_obj *obj);
#endif
