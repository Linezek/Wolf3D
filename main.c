/*
** pixel.c for lapin in /home/galpin_a/rendu/infographie/pixel
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Mon Nov  9 10:56:17 2015 Antoine Galpin
** Last update Sat Dec 26 17:12:38 2015 Galpin
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <lapin.h>
#include <lapin_enum.h>
#include "wolf3d.h"

int			make_map(t_wolf3d *w3d, char *file)
{
  file = "map.ini";
  w3d->map.i = 0;
  w3d->map.x = 0;
  w3d->map.y = 0;
  if ((file = bunny_load_ini(file)) == NULL)
    return (EXIT_ON_ERROR);
  w3d->map.xmax = my_getnbr(bunny_ini_get_field(file, "level1", "width", 0));
  w3d->map.ymax = my_getnbr(bunny_ini_get_field(file, "level1", "height", 0));
  if ((w3d->map.map
       = bunny_malloc(sizeof(char *) * (w3d->map.ymax + 1))) == NULL)
    return (my_putstr("malloc fail"));
  while (w3d->map.y < w3d->map.ymax)
    {
      if ((w3d->map.map[w3d->map.y]
      = bunny_malloc(sizeof(char) * (w3d->map.xmax + 1))) == NULL)
	return (my_putstr("fail malloc\n"));
      while (w3d->map.x < w3d->map.xmax)
	w3d->map.map[w3d->map.y][w3d->map.x++]
      = my_getnbr(bunny_ini_get_field(file, "level1", "data", w3d->map.i++)) + 48;
      w3d->map.x = 0;
      w3d->map.y++;
    }
  bunny_free(w3d->map.map);
  return (GO_ON);
}

t_bunny_response                move(t_bunny_event_state state,
                                     t_bunny_keysym keysym, void *data)
{
  t_wolf3d                      *w3d;

  (void)state;
  w3d = data;
  w3d->move.vitmv = 0.1;
  w3d->move.vitRotation = 0.1;
  if (keysym == BKS_UP || keysym == BKS_Z)
    key_up(w3d);
  if (keysym == BKS_DOWN || keysym == BKS_S)
    key_down(w3d);
  if (keysym == BKS_LEFT || keysym == BKS_Q)
    key_left(w3d);
  if (keysym == BKS_RIGHT || keysym == BKS_D)
    key_right(w3d);
  if (keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else
    return (GO_ON);
}

t_bunny_response		mainloop(void *data)
{
  t_wolf3d			*w3d;

  w3d = data;
  bunny_set_key_response(move);
  bunny_blit(&w3d->win->buffer, &w3d->pix->clipable, NULL);
  bunny_display(w3d->win);
  return (GO_ON);
}

int				Wolf3D(t_wolf3d *w3d, char *file)
{
  if ((make_map(w3d, file) == -1))
    return (-1);
  if ((w3d->win = bunny_start(WIDTH, HEIGHT, false, "Dat wolf3d")) == NULL)
    return (-1);
  if ((w3d->pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (-1);
  w3d->posX = 22;
  w3d->posY = 11.5;
  w3d->ray.dirX = -1;
  w3d->ray.dirY = 0;
  w3d->cam.planeX = 0;
  w3d->cam.planeY = -1;
  make_all(w3d);
  return (0);
}

int				main(int ac, char **av)
{
  t_wolf3d			*w3d;
  t_bunny_sound			*sound;

  if (ac != 1)
    return (my_putstr("Usage: ./wolf3d\n"));
  if ((w3d = bunny_malloc(sizeof(t_wolf3d))) == NULL)
    return (my_putstr("malloc failed"));
  if ((Wolf3D(w3d, av[0]) == -1))
    return (-1);
  sound = bunny_load_music("pokemon.ogg");
  bunny_set_loop_main_function(&mainloop);
  bunny_sound_play(sound);
  bunny_loop(w3d->win, 60, w3d);
  bunny_delete_clipable(&w3d->pix->clipable);
  bunny_stop(w3d->win);
  return (EXIT_ON_SUCCESS);
}
