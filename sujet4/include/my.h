/*
** my.h for gfx_colle_fantasy2 in /gfx_colle_fantasy2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 18:49:31 2016 Antoine Baché
** Last update Thu Jan 14 05:12:48 2016 Antoine Baché
*/

#ifndef MY_H_
# define MY_H_
# define UNUSED __attribute__((unused))
# define GREY 0xC8C8C8

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <lapin.h>

typedef struct		s_cone
{
  float			teta;
  float			rad;
}			t_cone;

typedef	struct		s_data
{
  t_bunny_window       	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*img;
  int			width;
  int			height;
  char			shape;
  t_cone		cone;
  t_bunny_position	player;
  t_bunny_position	*mouse_pos;
}			t_data;

void			cone_to_pix(t_bunny_pixelarray *,
				    t_cone *,
				    t_bunny_position *, unsigned int);
void			tekpixel(t_bunny_pixelarray *, t_bunny_position *,
				 unsigned int);
void			tekcircle_to_pix(t_bunny_pixelarray *,
					 unsigned int, float,
					 t_bunny_position *);
void			show_background(t_data *);
void			replace_display(t_data *);
void			select_shape(t_data *);
void			circle_shape(t_data *);
void			cone_shape(t_data *);
void			fill_color(t_data *, unsigned int);
t_bunny_response	my_fct_free(t_data *, int);

#endif /* !MY_H */
