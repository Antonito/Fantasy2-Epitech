
/*
** zelda.c for gfx_colle_fantasy2 in /fantasy2_2020/sujet4/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Jan 14 02:07:13 2016 Antoine Baché
** Last update Thu Jan 14 07:17:27 2016 edouard puillandre
*/

#include "my.h"

void		replace_display(t_data *data)
{
  int		i;
  t_color	*foreground;
  t_color	*background;

  i = -1;
  background = data->img->pixels;
  foreground = data->pix->pixels;
  while (++i < data->width * data->height)
    if (foreground[i].full == (unsigned int)WHITE)
      foreground[i].full = background[i].full;
}

void	circle_shape(t_data *data)
{
  int	i;

  i = -1;
  while (++i < 400)
    tekcircle_to_pix(data->pix, WHITE, ((double)(i) / 1000), &data->player);
}

void		cone_shape(t_data *data)
{
  unsigned int	color;
  int		x;
  int		y;
  int		max;

  data->cone.rad = 0;
  color = (unsigned int)WHITE;
  cone_to_pix(data->pix, &data->cone, &data->player, color);
  x = data->mouse_pos->x - data->player.x;
  y = data->mouse_pos->y - data->player.y;
  max = sqrt(x * x + y * y);
  if (max > 300)
	max = 300;
  data->cone.teta =((atan2(data->mouse_pos->y - data->player.y,
			   data->mouse_pos->x - data->player.x) * 180)
		    / M_PI) + 360;
  while (++data->cone.rad < max)
    cone_to_pix(data->pix, &data->cone, &data->player, color);
}

void	select_shape(t_data *data)
{
  if (data->shape == 0)
    cone_shape(data);
  else if (data->shape == 1)
    circle_shape(data);
}

void	show_background(t_data *data)
{
  select_shape(data);
  replace_display(data);
}
