/*
** put_circle.c for gfx_colle_fantasy2 in /fantasy2_2020/sujet3/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 21:35:55 2016 Antoine Baché
** Last update Thu Jan 14 05:51:42 2016 Antoine Baché
*/

#include "my.h"

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos, unsigned int color)
{
  t_color	*tmp;

  if (pos[0].x < pix->clipable.clip_width &&
      pos[0].y < pix->clipable.clip_height && pos[0].x >= 0 && pos[0].y >= 0)
    {
      tmp = (t_color*)pix->pixels +
	pos[0].x + pos[0].y * pix->clipable.clip_width;
      tmp->full = color;
    }
}

void			random_tekcircle_to_pix(t_bunny_pixelarray	*pix,
						unsigned int		color,
						float			rad,
						t_bunny_position	*pos)
{
  float			teta;
  t_bunny_position	pos_c;
  float			width;
  float			height;

  teta = 0;
  pos->x += ((float)(rand() % 1000) / 100) * (rand() % 100);
  pos->y += ((float)(rand() % 1000) / 100) * (rand() % 100);
  width = rad * pix->clipable.buffer.width / 2;
  height = rad * pix->clipable.buffer.height / 2;
  while (teta <= 90)
    {
      pos_c.x = (width * cos(teta * M_PI / 180) + pos->x);
      pos_c.y = (height * sin(teta * M_PI / 180) + pos->y);
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

void			tekcircle_to_pix(t_bunny_pixelarray	*pix,
					 unsigned int		color,
					 float			rad,
					 t_bunny_position	*pos)
{
  float			teta;
  t_bunny_position	pos_c;
  float			width;
  float			height;

  teta = 0;
  width = rad * pix->clipable.buffer.width / 2;
  height = rad * pix->clipable.buffer.height / 2;
  while (teta <= 90)
    {
      pos_c.x = width * cos(teta * M_PI / 180) + pos->x;
      pos_c.y = height * sin(teta * M_PI / 180) + pos->y;
      tekpixel(pix, &pos_c, color);
      pos_c.y = 2 * pos->y - (pos_c.y);
      tekpixel(pix, &pos_c, color);
      pos_c.x = 2 * pos->x - (pos_c.x);
      tekpixel(pix, &pos_c, color);
      pos_c.y = 2 * pos->y - pos_c.y;
      tekpixel(pix, &pos_c, color);
      teta = teta + 0.1;
    }
}
