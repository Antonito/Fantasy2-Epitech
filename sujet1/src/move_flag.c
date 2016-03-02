/*
** move_flag.c for gfx_colle_fantasy2 in /fantasy2_2020/sujet1/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 20:02:13 2016 Antoine Baché
** Last update Thu Jan 14 01:11:36 2016 edouard puillandre
*/

#include "my.h"

void		fill_column(t_data *data, int deb, int i)
{
  int		j;
  int		k;
  t_color	*color_old;
  t_color	*color_new;

  j = - 1;
  color_old = data->flag->pixels;
  color_new = data->pix->pixels;
  while (++j < data->pix->clipable.buffer.height)
    {
      if (data->inv == 0)
	k = (j - deb) * data->width + i;
      else
	k = (j - deb) * data->width + data->width - i + 1;
      if (j >= deb && j < deb + data->height)
	color_new[j * data->width + i].full = color_old[k].full;
      else
	color_new[j * data->width + i].full = WHITE;
    }
}

void   	move_flag(t_data *data)
{
  int		i;
  float		deb;

  i = - 1;
  data->var = data->var + data->dir;
  if (data->var == END_WHILE)
    data->dir = - 1;
  else if (data->var == 0)
    data->dir = 1;
  while (++i < data->width)
    {
      deb = sin((float) i / data->wind + (float) data->var / data->speed) * 10;
      deb = deb + data->pix->clipable.buffer.height / 4 * RATIO;
      fill_column(data, (int) deb, i);
    }
}
