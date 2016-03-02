/*
** my.h for gfx_colle_fantasy2 in /fantasy2_2020/sujet2/include
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Thu Jan 14 01:52:41 2016 edouard puillandre
** Last update Thu Jan 14 07:07:01 2016 Antoine Baché
*/

#ifndef MY_H_
# define MY_H_
# define UNUSED __attribute__((unused))
# define WIN_X 1024
# define WIN_Y 768
# define RAD 4
# define DROP 100

# include <unistd.h>
# include <stdlib.h>
# include <lapin.h>
# include <math.h>

typedef struct		s_blooddrop
{
  float			x;
  float			y;
  float			speed_x;
  float			speed_y;
  int			start;
  int			rad_x;
  int			rad_y;
  unsigned int		color;
}			t_blooddrop;

typedef	struct		s_data
{
  t_bunny_window       	*win;
  t_bunny_pixelarray	*pix;
  t_blooddrop		*blood;
  t_bunny_position	*mous_pos;
  int			drop;
  int			rad;
  float			speed_y;
  float			speed_x;
  int			step;
  int			var;
  int			count;
}			t_data;

t_bunny_response	my_fct_free(t_data *, int);
void			tekpixel(t_bunny_pixelarray *,
				 t_bunny_position *,
				 unsigned int);
int			init_pix_data(t_data *);
void			tekdisk(t_bunny_pixelarray *,
				t_bunny_position *,
				unsigned int,
				t_bunny_position *);
void			bloodfall(t_data *, int);

#endif /* !MY_H */
