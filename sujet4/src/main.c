/*
** main.c for gfx_colle_fantasy2 in /gfx_colle_fantasy2/sujet1/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 19:00:36 2016 Antoine Baché
** Last update Thu Jan 14 07:20:21 2016 Antoine Baché
*/

#include "my.h"

t_bunny_response	mainloop(t_data *data)
{
  fill_color(data, BLACK);
  show_background(data);
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response	mouse(UNUSED t_bunny_event_state	state,
			      UNUSED t_bunny_mousebutton     	key,
			      t_data    			*data)
{
  const bool		*mouse_click;

  mouse_click = bunny_get_mouse_button();
  if (mouse_click[BMB_LEFT] == 1)
    data->shape = ((data->shape == 1) ? 0 : 1);
#ifdef	DEBUG
  if (data->shape == 0)
    write(1, "Shape : Cone\n", 13);
  else
    write(1, "Shape : Circle\n", 15);
#endif
  return (GO_ON);
}

t_bunny_response	escape(t_bunny_event_state	state,
			       t_bunny_keysym		key,
			       t_data			*data)
{
  const	bool		*keys;

  keys = bunny_get_keyboard();
  if (state == GO_DOWN && keys[BKS_UP] == 1 && data->player.y > 3)
    data->player.y -= 3;
  else if (state == GO_DOWN && keys[BKS_DOWN] == 1 && data->player.y <
	   data->height - 4)
    data->player.y += 3;
  if (state == GO_DOWN && keys[BKS_LEFT] == 1 && data->player.x > 3)
    data->player.x -= 3;
  else if (state == GO_DOWN && keys[BKS_RIGHT] == 1 && data->player.x <
	   data->width - 4)
    data->player.x += 3;
  if (state != GO_UP || key != BKS_ESCAPE)
    return (GO_ON);
  return (my_fct_free(data, 0));
}

int	       	zelda(char *path)
{
  t_data	*data;

  if ((data = bunny_malloc(sizeof(t_data))) == NULL ||
      (data->img = bunny_load_pixelarray(path)) == NULL)
    return (1);
  data->width = data->img->clipable.buffer.width;
  data->height = data->img->clipable.buffer.height;
  if ((data->win = bunny_start(data->width, data->height, false, "Zelda"))
      == NULL ||
      (data->pix = bunny_new_pixelarray(data->width, data->height)) == NULL)
    return (1);
  data->player.x = data->width / 2;
  data->player.y = data->height / 2;
  data->shape = 0;
  data->mouse_pos = (t_bunny_position *)bunny_get_mouse_position();
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)escape);
    bunny_set_click_response((t_bunny_click)mouse);
  if (bunny_loop(data->win, 60, data) == EXIT_ON_ERROR)
    return (1);
  return (0);
}

int	main(UNUSED int ac, char **av, char **env)
{
  if (ac != 2)
    {
      write(2, "Usage: ./zelda background_path\n", 31);
      return (1);
    }
  if (*env == NULL || zelda(av[1]) == 1)
    return (1);
#ifdef	DEBUG
  write(1, "STATUS: OK\n", 11);
#endif
  return (0);
}
