/*
** put_circle.c for gfx_colle_fantasy2 in /fantasy2_2020/sujet2
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Thu Jan 14 02:25:20 2016 edouard puillandre
** Last update Thu Jan 14 07:10:23 2016 Antoine Baché
*/

#include "my.h"

void			tekcircle(t_bunny_pixelarray	*pix,
				  t_bunny_position	*pos,
				  unsigned int		color,
				  t_bunny_position	*rad)
{
  float			teta;
  t_bunny_position	pos_c;

  teta = 0;
  while (teta <= 90)
    {
      pos_c.x = rad->x * cos(teta * M_PI / 180) + pos->x;
      pos_c.y = rad->y * sin(teta * M_PI / 180) + pos->y;
      tekpixel(pix, &pos_c, color);
      pos_c.y = 2 * pos->y - pos_c.y;
      tekpixel(pix, &pos_c, color);
      pos_c.x = 2 * pos->x - pos_c.x;
      tekpixel(pix, &pos_c, color);
      pos_c.y = 2 * pos->y - pos_c.y;
      tekpixel(pix, &pos_c, color);
      teta = teta + 0.1;
    }
}

void			tekdisk(t_bunny_pixelarray	*pix,
				t_bunny_position	*pos,
				unsigned int		color,
				t_bunny_position	*rad)
{
  t_bunny_position	var;

  var.x = 1;
  var.y = 1;
  while (var.x <= rad->x && var.y <= rad->y)
    {
      tekcircle(pix, pos, color, &var);
      if (var.x < rad->x || var.y >= rad->y)
	var.x = var.x + 1;
      if (var.y < rad->y || var.x >= rad->x)
	var.y = var.y + 1;
    }
}
