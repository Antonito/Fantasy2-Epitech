/*
** blooddrops.c for gfx_colle_fantasy2 in /fantasy2_2020/sujet2
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Thu Jan 14 01:54:58 2016 edouard puillandre
** Last update Thu Jan 14 07:07:35 2016 Antoine Baché
*/

#include "my.h"

int			check_blood(t_data *data, int i)
{
  t_bunny_position	pos;
  t_bunny_position	rad;
  t_bunny_position	pos_old;

  pos.x = (int) data->blood[i].x + data->blood[i].speed_x;
  pos.y = (int) data->blood[i].y + data->blood[i].speed_y;
  pos_old.x = (int) data->blood[i].x;
  pos_old.y = (int) data->blood[i].y;
  rad.x = data->blood[i].rad_x;
  rad.y = data->blood[i].rad_y;
  if (data->blood[i].rad_x == 1 || data->blood[i].rad_y == 1)
      return (- 1);
  tekdisk(data->pix, &pos_old, BLACK, &rad);
  if (pos.x + data->rad >= data->pix->clipable.buffer.width - 1 ||
      pos.x - data->rad < 0)
    {
      data->blood[i].rad_x = data->blood[i].rad_x - 1;
      data->blood[i].rad_y = data->blood[i].rad_y + 1;
    }
  else if (pos.y + data->rad >= data->pix->clipable.buffer.height - 1)
    {
      data->blood[i].rad_x = data->blood[i].rad_x + 1;
      data->blood[i].rad_y = data->blood[i].rad_y - 1;
    }
  return (0);
}

void			printdrop(t_data *data, int i)
{
  t_bunny_position	pos;
  t_bunny_position	rad;

  pos.x = (int) data->blood[i].x;
  pos.y = (int) data->blood[i].y;
  rad.x = data->blood[i].rad_x;
  rad.y = data->blood[i].rad_y;
  data->blood[i].x = data->blood[i].x + data->blood[i].speed_x;
  data->blood[i].y = data->blood[i].y + data->blood[i].speed_y;
  if (data->blood[i].speed_x > 0.1)
    data->blood[i].speed_x = data->blood[i].speed_x - 0.03;
  else if (data->blood[i].speed_x < - 0.1)
    data->blood[i].speed_x = data->blood[i].speed_x + 0.03;
  else
    data->blood[i].speed_x = 0;
  pos.x = (int) data->blood[i].x;
  pos.y = (int) data->blood[i].y;
  tekdisk(data->pix, &pos, data->blood[i].color, &rad);
}

void	my_reinit(t_data *data, int i)
{
  data->blood[i].start = data->blood[i].start - data->var;
  data->blood[i].speed_x = data->speed_x;
  data->blood[i].x = data->mous_pos->x;
  data->blood[i].y = data->mous_pos->y;
  data->blood[i].rad_x = data->rad;
  data->blood[i].rad_y = data->rad;
  data->blood[i].speed_y = data->speed_y;
}

void	bloodfall(t_data *data, int cursor_true)
{
  int	i;

  i = - 1;
  while (++i < data->drop)
    {
      if (data->blood[i].start <= 0)
	if (check_blood(data, i) == 0)
	  printdrop(data, i);
	else
	  {
	    data->blood[i].x = data->blood[i].y = 0;
	    data->blood[i].start = data->blood[data->drop - 1].start
	      + data->step;
	      data->blood[i].speed_y = data->speed_y;
	      data->blood[i].rad_x = data->rad;
	      data->blood[i].rad_y = data->rad;
	  }
      else if (cursor_true == 1)
	my_reinit(data, i);
    }
}
