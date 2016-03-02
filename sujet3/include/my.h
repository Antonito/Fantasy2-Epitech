/*
** my.h for gfx_colle_fantasy2 in /gfx_colle_fantasy2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 18:49:31 2016 Antoine Baché
** Last update Thu Jan 14 07:11:17 2016 Antoine Baché
*/

#ifndef MY_H_
# define MY_H_
# define UNUSED __attribute__((unused))
# define WIN_X 1024
# define WIN_Y 768

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <lapin.h>

typedef	struct		s_data
{
  t_bunny_window       	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	*mouse_pos;
  int			loop;
  char			is_black;
  char			light_toggle;
}			t_data;

void			wand_light(t_data *);
void			fill_color(t_bunny_pixelarray *, unsigned int);
void			here_comes_the_light(t_data *);
t_bunny_response	my_fct_free(t_data *, int);
void			set_to_black(t_data *);
void			set_to_full_black(t_data *);
void			spread_color(t_data *, t_color *);
void			tekpixel(t_bunny_pixelarray *, t_bunny_position *,
				 unsigned int);
void			tekcircle_to_pix(t_bunny_pixelarray *, unsigned int,
					 float, t_bunny_position *);
void			random_tekcircle_to_pix(t_bunny_pixelarray *,
						unsigned int,
						float, t_bunny_position *);

#endif /* !MY_H */
