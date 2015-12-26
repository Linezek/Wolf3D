/*
** move.c for zerty in /home/galpin_a/galpin_a/rendu/infographie/gfx_wolf3d
**
** Made by Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Sat Dec  5 23:52:02 2015 Galpin
** Last update Sat Dec 26 17:10:17 2015 Galpin
*/

#include <lapin.h>
#include <lapin_enum.h>
#include "wolf3d.h"

void		make_all(t_wolf3d *w3d)
{
  w3d->size.y = 0;
  w3d->size.x = 0;
  while (w3d->size.x <= WIDTH)
    {
      correction(w3d);
      raycasting(w3d);
      hit_the_wall(w3d);
      colonne(w3d);
      sky_and_ground(w3d);
      w3d->size.x++;
    }
}

void		key_up(t_wolf3d *w3d)
{
  if (w3d->map.map
      [(int)(w3d->posX + w3d->ray.dirX * w3d->move.vitmv)]
      [(int)(w3d->posY)] == '0')
    w3d->posX += w3d->ray.dirX * w3d->move.vitmv;
  if (w3d->map.map[(int)(w3d->posX)]
      [(int)(w3d->posY + w3d->ray.dirY * w3d->move.vitmv)] == '0')
    w3d->posY += w3d->ray.dirY * w3d->move.vitmv;
  make_all(w3d);
}

void		key_down(t_wolf3d *w3d)
{
  if (w3d->map.map
      [(int)(w3d->posX - w3d->ray.dirX * w3d->move.vitmv)]
      [(int)(w3d->posY)] == '0')
    w3d->posX -= w3d->ray.dirX * w3d->move.vitmv;
  if (w3d->map.map[(int)(w3d->posX)]
      [(int)(w3d->posY - w3d->ray.dirY * w3d->move.vitmv)] == '0')
    w3d->posY -= w3d->ray.dirY * w3d->move.vitmv;
  make_all(w3d);
}

void		key_left(t_wolf3d *w3d)
{
  w3d->move.oldDirX = w3d->ray.dirX;
  w3d->ray.dirX = w3d->ray.dirX * cos(-w3d->move.vitRotation)
  - w3d->ray.dirY * sin(-w3d->move.vitRotation);
  w3d->ray.dirY = w3d->move.oldDirX * sin(-w3d->move.vitRotation)
  + w3d->ray.dirY * cos(-w3d->move.vitRotation);
  w3d->cam.oldPlaneX = w3d->cam.planeX;
  w3d->cam.planeX = w3d->cam.planeX * cos(-w3d->move.vitRotation)
  - w3d->cam.planeY * sin(-w3d->move.vitRotation);
  w3d->cam.planeY = w3d->cam.oldPlaneX * sin(-w3d->move.vitRotation)
  + w3d->cam.planeY * cos(-w3d->move.vitRotation);
  make_all(w3d);
}

void		key_right(t_wolf3d *w3d)
{
  w3d->move.oldDirX = w3d->ray.dirX;
  w3d->ray.dirX = w3d->ray.dirX * cos(w3d->move.vitRotation)
  - w3d->ray.dirY * sin(w3d->move.vitRotation);
  w3d->ray.dirY = w3d->move.oldDirX * sin(w3d->move.vitRotation)
  + w3d->ray.dirY * cos(w3d->move.vitRotation);
  w3d->cam.oldPlaneX = w3d->cam.planeX;
  w3d->cam.planeX = w3d->cam.planeX * cos(w3d->move.vitRotation)
  - w3d->cam.planeY * sin(w3d->move.vitRotation);
  w3d->cam.planeY = w3d->cam.oldPlaneX * sin(w3d->move.vitRotation)
  + w3d->cam.planeY * cos(w3d->move.vitRotation);
  make_all(w3d);
}
