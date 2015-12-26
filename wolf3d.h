/*
** wolf3d.h for zertyui in /home/galpin_a/galpin_a/rendu/infographie/gfx_wolf3d
**
** Made by Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Mon Nov 30 20:04:06 2015 Galpin
** Last update Sat Dec 26 17:22:48 2015 Galpin
*/

#ifndef WOLF3D_H_
# define WOLF3D_H_

#include <lapin.h>
#include <math.h>

# define HEIGHT 600
# define WIDTH 1000
# define ABS(x)	((x) > 0 ? (x) : -(x))
# define GROUND 0x656565
# define SKY 0xFEE500
# define WALL 0xf2f2f2
# define DARKWALL 0xCCCCCC

typedef	struct			s_size
{
  int				hit;
  float				side;
  float				heightLine;
  float				h;
  int				y;
  int				x;
}				t_size;

typedef	struct			s_raycating
{
  float				dirX;
  float				dirY;
  float				wall_dist;
  float				rayDirX;
  float				rayDirY;
  float				rayPosX;
  float				rayPosY;
  float				stepX;
  float				stepY;
  float				sideDistY;
  float				sideDistX;
  float				deltaDistX;
  float				deltaDistY;
  float				wallDistY;
}				t_raycasting;

typedef	struct			s_camera
{
  float				planeX;
  float				planeY;
  float				cameraX;
  float				oldPlaneX;
}				t_camera;

typedef	struct			t_move
{
  float				vitmv;
  float				vitRotation;
  float				oldDirX;
}				t_move;

typedef	struct			s_draw
{
  int				drawStart;
  int				drawEnd;
  t_color			color;
}				t_draw;

typedef struct			s_map
{
  int				i;
  int				x;
  int				y;
  float				mapX;
  float				mapY;
  int				ymax;
  int				xmax;
  char				**map;
}				t_map;

typedef struct			s_wolf3d
{
  t_bunny_window		*win;
  t_bunny_position		pos;
  t_bunny_pixelarray		*pix;
  float				posX;
  float				posY;
  t_map				map;
  t_raycasting			ray;
  t_camera			cam;
  t_draw			draw;
  t_move			move;
  t_size			size;
}				t_wolf3d;

t_bunny_response		mainloop(void *data);
void				key_up(t_wolf3d *w3d);
void				key_down(t_wolf3d *w3d);
void				key_left(t_wolf3d *w3d);
void				key_right(t_wolf3d *w3d);
void				hit_the_wall(t_wolf3d *w3d);
void				raycasting(t_wolf3d *w3d);
void				correction(t_wolf3d *w3d);
void				colonne(t_wolf3d *w3d);
void				my_putchar(char c);
void				make_all(t_wolf3d *w3d);
void				sky_and_ground(t_wolf3d *w3d);
void				tekpixel(t_bunny_pixelarray *pix,
					 t_bunny_position *pos,
					 t_color *color);
int				my_getnbr(const char *str);
int				make_map(t_wolf3d *w3d, char *file);
int				Wolf3D(t_wolf3d *w3d, char *file);
int				my_putstr(char *str);
int				main(int ac, char **av);

#endif /* !WOL3D_H_ */
