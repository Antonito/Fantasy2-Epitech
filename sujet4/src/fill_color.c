/*
** fill_color.c for gfx_colle_fantasy in /fantasy2_2020/sujet4/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Jan 14 01:46:32 2016 Antoine Baché
** Last update Thu Jan 14 03:12:29 2016 Antoine Baché
*/

#include "my.h"

void		fill_color(t_data *data, unsigned int color)
{
  int		i;
  t_color	*colors;

  i = -1;
  colors = data->pix->pixels;
  while (++i < data->width * data->height)
    colors[i].full = color;
}
