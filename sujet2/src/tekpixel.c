/*
** tekpixel.c for gfx_colle_fantasy2 in /fantasy2_2020/sujet2/src/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Jan 14 01:50:29 2016 edouard puillandre
** Last update Thu Jan 14 04:54:38 2016 edouard puillandre
*/

#include <my.h>

void			tekpixel(t_bunny_pixelarray	*pix,
				 t_bunny_position	*pos,
				 unsigned int		color)
{
  t_color	*my_color;
  int	       	pos_pixel;
  int	       	max;

  pos_pixel = pos->x + pos->y * pix->clipable.buffer.width;
  max = pix->clipable.buffer.width * pix->clipable.buffer.height;
  my_color = pix->pixels;
  if (pos_pixel < max && pos_pixel >= 0)
    my_color[pos_pixel].full = color;
}
