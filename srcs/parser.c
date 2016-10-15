#include "../includes/rtv1.h"

t_cam		*ft_new_camera(t_vec *pos, t_vec *dir)
{
	t_cam	*c;

	if (!(c = (t_cam *)malloc(sizeof(t_cam))))
		return (NULL);
	c->pos = pos;
	c->dir = dir;
	return (c);
}

t_scene		*ft_get_scene(void)
{
	static t_scene *s;

	s = NULL;
	if (s == NULL)
	{
		if (!(s = (t_scene *)malloc(sizeof(t_scene))))
			return (NULL);
		s->cam = NULL;
		s->cone = NULL;
		s->cylind = NULL;
		s->plan = NULL;
		s->sphere = NULL;
		s->spot = NULL;
	}
	return (s);
}

t_scene		*ft_init_scene(char *scene)
{
	char	*line;
	int		fd;
	int		ret;
	t_scene	*s;

	fd = open(scene, O_RDONLY);
	s = ft_get_scene();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strstr(line, "camera:"))
			s->cam = ft_get_camera(fd);
		if (ft_strstr(line, "cone:"))
			s->cone = ft_get_cones(fd);
		if (ft_strstr(line, "cylindre:"))
			s->cylind = ft_get_cylinds(fd);
		if (ft_strstr(line, "plan:"))
			s->plan = ft_get_plans(fd);
		if (ft_strstr(line, "sphere:"))
			s->sphere = ft_get_spheres(fd);
		if (ft_strstr(line, "spot:"))
			s->spot = ft_get_spots(fd);
	}
	if (ret == -1)
		exit (-1);
	return (s);
}
