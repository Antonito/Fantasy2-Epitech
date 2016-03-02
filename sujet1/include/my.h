/*
** my.h for gfx_colle_fantasy2 in /gfx_colle_fantasy2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 18:49:31 2016 Antoine Baché
** Last update Thu Jan 14 00:57:07 2016 edouard puillandre
*/

#ifndef MY_H_
# define MY_H_
# define RATIO 0.33
# define END_WHILE 100000
# define UNUSED __attribute__((unused))

# include <unistd.h>
# include <stdlib.h>
# include <lapin.h>
# include <math.h>

typedef	struct		s_data
{
  t_bunny_window       	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*flag;
  int			height;
  int			width;
  int			var;
  int			dir;
  int			wind;
  int			speed;
  int			inv;
}			t_data;

void			move_flag(t_data *);
t_bunny_response	my_fct_free(t_data *, int);
int			cpy_pix(t_data *, char *, double);

#endif /* !MY_H */
