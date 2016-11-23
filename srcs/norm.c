#include "../includes/rtv1.h"

t_vec   normale(t_obj *obj, t_env *env, t_vec cam)
{
  t_vec   result;
  t_vec   tmp;
  t_vec   temp;

  (void)env;
  if (obj->type == 0)
      result = obj->rot;
  else
  {
    if (obj->type == 1)
      result = sub_vect(obj->pos, cam);
    else
    {
        temp = scale_vect(obj->rot, dot_vect(env->ray_dir, obj->rot) * env->d + dot_vect(sub_vect(env->cam_pos, obj->pos), obj->rot));
        if (obj->type == 2)
          temp = scale_vect(temp, (1 + pow(tan(obj->size), 2)));
        tmp = sub_vect(cam, obj->pos);
        result = sub_vect(temp, tmp);
    }
  }
  result = norm_vect(result);
  return (result);
}
