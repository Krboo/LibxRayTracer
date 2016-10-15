/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:08:43 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/14 18:24:57 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

# define HEIGHT	750
# define WIDTH	750

typedef	struct		s_pos
{
	double			x;
	double			y;
	double			z;
}					t_pos;

typedef	struct		s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct		s_img
{
	char			*data;
	int				bpp;
	int				endian;
	int				sl;
	void			*img;
}					t_img;

typedef	struct		s_cam
{
	t_pos			*pos;
	t_pos			*dir;
}					t_cam;

typedef	struct		s_cone
{
	double			alpha;
	t_color			*color;
	t_pos			*pos;
	struct s_cone	*next;
}					t_cone;

typedef struct		s_cylind
{
	double			radius;
	t_color			*color;
	t_pos			*pos;
	struct s_cylind	*next;
}					t_cylind;

typedef struct		s_plan
{
	double			dis;
	t_color			*color;
	t_pos			*pos;
	struct s_plan	*next;
}					t_plan;

typedef struct		s_sphere
{
	double			radius;
	t_color			*color;
	t_pos			*pos;
	struct s_sphere	*next;
}					 t_sphere;

typedef struct		s_spot
{
	t_color			*color;
	t_pos			*pos;
	struct s_spot	*next;
}					t_spot;

typedef struct		s_scene
{
	t_cam			*cam;
	t_cone			*cone;
	t_cylind		*cylind;
	t_plan			*plan;
	t_sphere		*sphere;
	t_spot			*spot;
}					t_scene;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
}					t_env;
/*
** camera.c
*/
t_cam				*ft_get_camera(int fd);
/*
** clear.c
*/
void				ft_deleted_cone(t_cone **start);
void				ft_deleted_cylindre(t_cylind **start);
void				ft_deleted_plan(t_plan **start);
void				ft_deleted_sphere(t_sphere **start);
void				ft_deleted_spot(t_spot **start);
/*
** color.c
*/
t_color				*ft_color(int fd);
t_color				*ft_new_color(double r, double g, double b);
void				ft_deleted_color(t_color *color);
/*
** cone.c
*/
t_cone				*ft_get_cone(int fd);
t_cone				*ft_get_cones(int fd);
t_cone				*ft_new_cone(double alpha, t_color *color, t_pos *pos);
void				ft_add_cone(t_cone *start, t_cone *new);
/*
** cylindre.c
*/
t_cylind			*ft_get_cylind(int fd);
t_cylind			*ft_get_cylinds(int fd);
t_cylind			*ft_new_cylind(double radius, t_color *color, t_pos *pos);
void				ft_add_cylind(t_cylind *start, t_cylind *new);
/*
** error.c
*/
void				ft_error(void);
void				ft_exit(char *s);
void				ft_free(t_env *env);
void				ft_free_error(t_env *env);
/*
** init.c
*/
t_cam				*ft_new_camera(t_pos *pos, t_pos *dir);
t_scene				*ft_get_scene(void);
void				ft_init_scene(char *scene);
/*
** parser.c
*/
void				ft_RTv1(char *scene);
/*
** plan.c
*/
t_plan				*ft_get_plan(int fd);
t_plan				*ft_get_plans(int fd);
t_plan				*ft_new_plan(double dis, t_color *color, t_pos *pos);
void				ft_add_plan(t_plan *start, t_plan *new);
/*
** sphere.c
*/
t_sphere			*ft_get_sphere(int fd);
t_sphere			*ft_get_spheres(int fd);
t_sphere			*ft_new_sphere(double radius, t_color *color, t_pos *pos);
void				ft_add_sphere(t_sphere *start, t_sphere *new);
/*
** spot.c
*/
t_spot				*ft_get_spot(int fd);
t_spot				*ft_get_spots(int fd);
t_spot				*ft_new_spot(t_color *color, t_pos *pos);
void				ft_add_spot(t_spot *start, t_spot *new);
/*
** tools_vect.c
*/
double				ft_magnitude(t_pos *v);
t_pos				*ft_neg(t_pos *v);
t_pos				*ft_norm(t_pos *v);
/*
** vect.c
*/
t_pos				*ft_new_vector(double x, double y, double z);
t_pos				*ft_vector(int fd);
void				ft_deleted_vect(t_pos *vect);

#endif
