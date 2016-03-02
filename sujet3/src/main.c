/*
** main.c for gfx_colle_fantasy2 in /gfx_colle_fantasy2/sujet1/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 19:00:36 2016 Antoine Baché
** Last update Thu Jan 14 01:22:22 2016 Antoine Baché
*/

#include "my.h"

t_bunny_response	mainloop(t_data *data)
{
  if (data->is_black == 0 && (++data->loop))
    set_to_full_black(data);
  else if (data->light_toggle == 0 && data->is_black == 1)
    {
      data->loop = 0;
      wand_light(data);
    }
  else if (data->light_toggle == 1 && (++data->loop))
    here_comes_the_light(data);
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response	mouse_events(UNUSED t_bunny_event_state	state,
				     UNUSED t_bunny_mousebutton	key,
				     t_data			*data)
{
  const bool		*mouse;

  mouse = bunny_get_mouse_button();
  if (data->is_black == 1 && mouse[BMB_LEFT] == true)
    data->light_toggle = 1;
  if (data->is_black == 1 && data->light_toggle == 1 &&
      mouse[BMB_RIGHT] == true)
    {
      fill_color(data->pix, WHITE);
      data->is_black = 0;
      data->light_toggle = 0;
      data->loop = 0;
      set_to_black(data);
    }
  return (GO_ON);
}

t_bunny_response	escape(t_bunny_event_state	state,
			       t_bunny_keysym		key,
			       t_data			*data)
{
  const bool		*mouse;

  mouse = bunny_get_mouse_button();
  if (data->is_black == 1 && mouse[BMB_LEFT] == true)
    data->light_toggle = 1;
  if (state != GO_UP || key != BKS_ESCAPE)
    return (GO_ON);
  return (my_fct_free(data, 0));
}

int	       	potter(void)
{
  t_data	*data;

  if ((data = bunny_malloc(sizeof(t_data))) == NULL ||
      (data->win = bunny_start(WIN_X, WIN_Y, false, "Potter"))  == NULL ||
      (data->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) == NULL)
    return (1);
  fill_color(data->pix, WHITE);
  data->is_black = 0;
  data->loop = 0;
  data->light_toggle = 0;
  data->mouse_pos = (t_bunny_position *)bunny_get_mouse_position();
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)escape);
  bunny_set_click_response((t_bunny_click)mouse_events);
  if (bunny_loop(data->win, 120, data) == EXIT_ON_ERROR)
    return (1);
  return (0);
}

int	main(UNUSED int ac, UNUSED char **av, char **env)
{
  if (*env == NULL || potter() == 1)
    return (1);
#ifdef	DEBUG
  write(1, "STATUS: OK\n", 11);
#endif
  return (0);
}
