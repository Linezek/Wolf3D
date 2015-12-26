/*
** vecnorm.c for aztyui in /home/galpin_a/galpin_a/rendu/infographie/gfx_wolf3d
**
** Made by Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Mon Nov 30 15:50:48 2015 Galpin
** Last update Thu Dec 24 00:00:07 2015 Galpin
*/

#include <lapin.h>
#include <math.h>

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  return (((pow((coord1->x - coord0->x), 2))
  + (pow((coord1->y - coord0->y), 2))));
}
