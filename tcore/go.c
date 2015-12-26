/*
** go.c for zertyu in /home/galpin_a/galpin_a/rendu/infographie/gfx_wolf3d
**
** Made by Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Mon Nov 30 15:58:31 2015 Galpin
** Last update Wed Dec 16 18:01:07 2015 Galpin
*/

#include <lapin.h>
#include <math.h>

void		go(t_bunny_position *curpos, double angle,
		   t_bunny_position *newpos, int move)
{
  newpos->x = cos(angle) * move + curpos->x;
  newpos->y = sin(angle) * move + curpos->y;
}
