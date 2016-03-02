/*
** my_init_fct.c for gfx_colle_fantasy2 in /fantasy2_2020/sujet2
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Thu Jan 14 01:54:58 2016 edouard puillandre
** Last update Thu Jan 14 07:09:07 2016 Antoine Baché
*/

#include "my.h"

int	my_init_blood(t_data	*data)
{
  int 	i;

  if ((data->blood = bunny_malloc(sizeof(t_blooddrop) * data->drop)) == NULL)
    return (1);
  i = - 1;
  while (++i < data->drop)
    {
      data->blood[i].x = 0;
      data->blood[i].y = 0;
      data->blood[i].start = i * data->step;
      data->blood[i].speed_y = data->speed_y;
      data->blood[i].speed_x = 0;
      data->blood[i].rad_x = data->rad;
      data->blood[i].rad_y = data->rad;
      data->blood[i].color = RED;
    }
  return (0);
}

int		init_pix_data(t_data *data)
{
  t_color	*color;
  int		i;

  color = data->pix->pixels;
  i = 0;
  while (i < data->pix->clipable.buffer.width *
	 data->pix->clipable.buffer.height)
    {
      color[i].full = BLACK;
      i = i + 1;
    }
  data->rad = RAD;
  data->drop = DROP;
  data->speed_y = 1;
  data->speed_x = 0;
  data->step = 50;
  data->var = 1;
  if (my_init_blood(data) == 1)
    return (1);
  return (0);
}
