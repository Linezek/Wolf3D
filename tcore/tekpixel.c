/*
** pixels.c for zertyu in /home/galpin_a/galpin_a/rendu/infographie/test
**
** Made by Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Fri Nov 20 13:35:35 2015 Galpin
** Last update Wed Dec 23 00:55:42 2015 Galpin
*/

#include <lapin.h>

void		tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
			 t_color *color)
{
  int		*draw;

  draw = pix->pixels;
  draw[pos->y * pix->clipable.buffer.width + pos->x] = color->full;
}
