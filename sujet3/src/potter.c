/*
** potter.c for gfx_colle_fantasy2 in /fantasy2_2020/sujet3/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 20:25:35 2016 Antoine Baché
** Last update Thu Jan 14 07:12:12 2016 Antoine Baché
*/

#include "my.h"

void		fill_color(t_bunny_pixelarray *pix, unsigned int color)
{
  int		i;
  t_color	*colors;

  i = -1;
  colors = pix->pixels;
  while (++i < WIN_X * WIN_Y)
    colors[i].full = color;
}

void	wand_light(t_data *data)
{
  int	i;

  i = -1;
  fill_color(data->pix, BLACK);
  while (++i < 100)
    tekcircle_to_pix(data->pix, WHITE, ((double)(i)) / 1000, data->mouse_pos);
}

void   		here_comes_the_light(t_data *data)
{
  t_color      	*colors;
  int  		i;

  colors = data->pix->pixels;
  colors[(WIN_X / 2) * (WIN_Y / 2)].full = BLACK;
  i = -1;
  while (++i < 500)
    tekcircle_to_pix(data->pix, WHITE, ((double)(data->loop + i)) / 2000,
		     data->mouse_pos);
  data->loop += (i - 1);
  if (data->loop >= 5000 ||
      (colors[0].full == (unsigned int)WHITE &&
       colors[WIN_X - 1].full == (unsigned int)WHITE))
    {
      data->light_toggle = 1;
      fill_color(data->pix, WHITE);
    }
}

void			set_to_full_black(t_data *data)
{
  t_color		*colors;
  t_bunny_position	pos;

  colors = data->pix->pixels;
  pos.x = WIN_X / 2;
  pos.y = WIN_Y / 2;
  colors[pos.x * pos.y].full = BLACK;
  tekcircle_to_pix(data->pix, BLACK, ((double)data->loop) / 1000, &pos);
  if (data->loop >= 1500)
    data->is_black = 1;
}

void			set_to_black(t_data *data)
{
  t_color		*colors;
  t_bunny_position	pos;

  colors = data->pix->pixels;
  pos.x = WIN_X / 2;
  pos.y = WIN_Y / 2;
  colors[pos.x * pos.y].full = BLACK;
  random_tekcircle_to_pix(data->pix, BLACK, ((double)data->loop) / 1000, &pos);
  if (data->loop >= 2000)
    data->is_black = 1;
}
