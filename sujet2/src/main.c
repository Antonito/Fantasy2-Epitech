/*
** main.c for gfx_colle_fantasy2 in /gfx_colle_fantasy2/sujet1/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 19:00:36 2016 Antoine Baché
** Last update Thu Jan 14 06:21:54 2016 edouard puillandre
*/

#include "my.h"

t_bunny_response	mainloop(t_data *data)
{
  if (data->count == 0)
    data->speed_x = 0;
  else
    data->count = data->count - 1;
  if (data->mous_pos->x >= 0 && data->mous_pos->y >= 0 &&
      data->mous_pos->x < data->pix->clipable.buffer.width &&
      data->mous_pos->y < data->pix->clipable.buffer.height)
    bloodfall(data, 1);
  else
    bloodfall(data, 0);
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response	escape(t_bunny_event_state	state,
			       t_bunny_keysym		key,
			       t_data			*data)
{
  if (state == GO_UP && key == BKS_ESCAPE)
    return (my_fct_free(data, 0));
  if (state == GO_UP && key == BKS_PAGEUP && data->rad < 20)
    data->rad = data->rad + 1;
  if (state == GO_UP && key == BKS_PAGEDOWN && data->rad > 0)
    data->rad = data->rad - 1;
  if (state == GO_UP && key == BKS_UP && data->var < 4)
    data->var = data->var + 1;
  if (state == GO_UP && key == BKS_DOWN && data->var > 1)
    data->var = data->var - 1;
  if (state == GO_UP && key == BKS_RIGHT && data->speed_y < 1.3)
    data->speed_y = data->speed_y + 0.1;
  if (state == GO_UP && key == BKS_LEFT && data->speed_y > 0.4)
    data->speed_y = data->speed_y - 0.1;
  return (GO_ON);
}

t_bunny_response	move(const t_bunny_position	*relative,
			     t_data			*data)
{
  if (relative->x > 0 && data->speed_x > - 2)
    data->speed_x = data->speed_x - 0.4;
  else if (relative->x < 0 && data->speed_x < 2)
    data->speed_x = data->speed_x + 0.4;
  data->count = 10;
  return (GO_ON);
}

int	       	blood(void)
{
  t_data	*data;

  if ((data = bunny_malloc(sizeof(t_data))) == NULL ||
      (data->win = bunny_start(WIN_X, WIN_Y, false, "Blood"))  == NULL ||
      (data->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) == NULL ||
      init_pix_data(data) == 1)
    return (1);
#ifdef	DEBUG
  write(1, "INIT: OK\n", 9);
#endif
  data->mous_pos = (t_bunny_position *)bunny_get_mouse_position();
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)escape);
  bunny_set_move_response((t_bunny_move)move);
  if (bunny_loop(data->win, 60, data) == EXIT_ON_ERROR)
    return (1);
  return (0);
}

int	main(UNUSED int ac, UNUSED char **av, char **env)
{
  if (*env == NULL || blood() == 1)
    return (1);
#ifdef	DEBUG
  write(1, "STATUS: OK\n", 11);
#endif
  return (0);
}
