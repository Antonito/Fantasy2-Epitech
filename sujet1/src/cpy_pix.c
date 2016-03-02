/*
** cpy_pix.c for gfx_colle_fantasy2 in /gfx_colle_fantasy2/sujet1
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Wed Jan 13 19:05:44 2016 edouard puillandre
** Last update Thu Jan 14 00:15:11 2016 edouard puillandre
*/

#include "my.h"

void			fill_pix(t_data			*data,
				 double			ratio,
				 t_bunny_pixelarray	*pix,
				 int			height)
{
  t_color		*color_old;
  t_color		*color_new;
  int			i;
  int			j;

  i = j = -1;
  color_old = pix->pixels;
  color_new = data->pix->pixels;
  while (++i < data->width * height)
    {
      if (i >= data->width * ((int) (data->height * ratio / 2)) &&
	  i < data->width * ((int) (data->height * (ratio + 2) / 2)))
	color_new[i].full = color_old[++j].full;
      else
	color_new[i].full = WHITE;
    }
}

int			cpy_pix(t_data *data, char *str, double ratio)
{
  int			height;

  if ((data->flag = bunny_load_pixelarray(str)) == NULL)
    return (1);
  data->width = data->flag->clipable.buffer.width;
  data->height = data->flag->clipable.buffer.height;
  height = data->flag->clipable.buffer.height * (1 + ratio);
  if ((data->win = bunny_start(data->width, height, false, "Rohan")) == NULL ||
      (data->pix = bunny_new_pixelarray(data->width, height)) == NULL)
    return (1);
  fill_pix(data, ratio, data->flag, height);
  return (0);
}
