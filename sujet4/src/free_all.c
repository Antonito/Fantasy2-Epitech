/*
** free_all.c for gfx_colle_fantasy2 in /gfx_colle_fantasy2/sujet1/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 18:55:44 2016 Antoine Baché
** Last update Wed Jan 13 19:02:10 2016 Antoine Baché
*/

#include "my.h"

t_bunny_response	my_fct_free(t_data *data, int error_true)
{
  bunny_delete_clipable(&data->pix->clipable);
  bunny_stop(data->win);
  bunny_free(data);
  if (error_true == 1)
    return (EXIT_ON_ERROR);
  return (EXIT_ON_SUCCESS);
}
