/*
** calcul.c for ertuiop in /home/galpin_a/galpin_a/rendu/infographie/gfx_wolf3d
**
** Made by Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Dec 22 15:58:41 2015 Galpin
** Last update Sat Dec 26 17:18:27 2015 Galpin
*/

#include <stdio.h>
#include <lapin.h>
#include "wolf3d.h"

void			correction(t_wolf3d *w3d)
{
  w3d->cam.cameraX = ((2.0 * (float)w3d->size.x) / WIDTH) - 1.0;
  w3d->ray.rayPosY = w3d->posY;
  w3d->ray.rayPosX = w3d->posX;
  w3d->ray.rayDirX = (w3d->ray.dirX + (w3d->cam.planeX * w3d->cam.cameraX));
  w3d->ray.rayDirY = (w3d->ray.dirY + (w3d->cam.planeY * w3d->cam.cameraX));
  w3d->map.mapX = (int)w3d->ray.rayPosX;
  w3d->map.mapY = (int)w3d->ray.rayPosY;
  w3d->ray.deltaDistX = sqrt(1.0 + (w3d->ray.rayDirY * w3d->ray.rayDirY)
  / (w3d->ray.rayDirX * w3d->ray.rayDirX));
  w3d->ray.deltaDistY = sqrt(1.0 + (w3d->ray.rayDirX * w3d->ray.rayDirX)
  / (w3d->ray.rayDirY * w3d->ray.rayDirY));
  w3d->size.hit = 0;
}

void			raycasting(t_wolf3d *w3d)
{
  if (w3d->ray.rayDirX < 0.0)
    {
      w3d->ray.stepX = -1.0;
      w3d->ray.sideDistX = (w3d->ray.rayPosX - w3d->map.mapX)
      * w3d->ray.deltaDistX;
    }
  else
    {
      w3d->ray.stepX = 1.0;
      w3d->ray.sideDistX = (w3d->map.mapX + 1.0 - w3d->ray.rayPosX)
      * w3d->ray.deltaDistX;
    }
  if (w3d->ray.rayDirY < 0)
    {
      w3d->ray.stepY = -1.0;
      w3d->ray.sideDistY = (w3d->ray.rayPosY - w3d->map.mapY)
      * w3d->ray.deltaDistY;
    }
  else
    {
      w3d->ray.stepY = 1.0;
      w3d->ray.sideDistY = (w3d->map.mapY + 1.0 - w3d->ray.rayPosY)
      * w3d->ray.deltaDistY;
    }
}

void			hit_the_wall(t_wolf3d *w3d)
{
  while (w3d->size.hit == 0)
    {
      if (w3d->ray.sideDistX < w3d->ray.sideDistY)
	{
	  w3d->ray.sideDistX += w3d->ray.deltaDistX;
	  w3d->map.mapX += w3d->ray.stepX;
	  w3d->size.side = 0;
	}
      else
	{
	  w3d->ray.sideDistY += w3d->ray.deltaDistY;
	  w3d->map.mapY += w3d->ray.stepY;
	  w3d->size.side = 1;
	}
      if (w3d->map.map[(int)w3d->map.mapX][(int)w3d->map.mapY] == '1')
	w3d->size.hit = 1;
    }
}

void			colonne(t_wolf3d *w3d)
{
  if (w3d->size.side == 0)
    w3d->ray.wallDistY = ABS((w3d->map.mapX - w3d->ray.rayPosX
  + (1.0 - w3d->ray.stepX) / 2.0) / w3d->ray.rayDirX);
  else
    w3d->ray.wallDistY = ABS((w3d->map.mapY - w3d->ray.rayPosY
  + (1.0 - w3d->ray.stepY) / 2.0) / w3d->ray.rayDirY);
  w3d->size.heightLine = ABS((int)(HEIGHT / w3d->ray.wallDistY));
  w3d->draw.drawStart =
  (int)((-1 * w3d->size.heightLine / 2.0) + (HEIGHT / 2.0));
  w3d->draw.drawEnd =
  (int)((w3d->size.heightLine / 2.0) + (HEIGHT / 2.0));
  if (w3d->draw.drawStart < 0)
    w3d->draw.drawStart = 0;
  if (w3d->draw.drawEnd >= HEIGHT)
    w3d->draw.drawEnd = HEIGHT - 1;
  w3d->size.y = w3d->draw.drawStart;
}

void			sky_and_ground(t_wolf3d *w3d)
{
  while (w3d->size.y < w3d->draw.drawEnd)
    {
      w3d->draw.color.full = WALL;
      if (w3d->size.side == 1)
	w3d->draw.color.full = DARKWALL;
      w3d->pos.y = w3d->size.y;
      w3d->pos.x = w3d->size.x;
      tekpixel(w3d->pix, &w3d->pos, &w3d->draw.color);
      w3d->size.y++;
    }
  if (w3d->draw.drawEnd < 0)
    w3d->draw.drawEnd = HEIGHT;
  w3d->size.y = w3d->draw.drawEnd;
  while (w3d->size.y < HEIGHT)
    {
      w3d->pos.y = w3d->size.y;
      w3d->pos.x = w3d->size.x;
      w3d->draw.color.full = GROUND;
      tekpixel(w3d->pix, &w3d->pos, &w3d->draw.color);
      w3d->draw.color.full = SKY;
      w3d->pos.y = HEIGHT - w3d->size.y - 1;
      tekpixel(w3d->pix, &w3d->pos, &w3d->draw.color);
      w3d->size.y++;
    }
}
