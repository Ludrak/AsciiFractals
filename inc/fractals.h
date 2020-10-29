
#ifndef FRACTALS_H
# define FRACTALS_H

# define MANDELBROT_ID  1
# define JULIA_ID       2

# define MULTI_J        -100

# define MAX_ITERATIONS 100000
# define M_INFINITY     20000

extern int      RES[2];
extern int      MAX_ITER;
extern double   DEF_X[2];
extern double   DEF_Y[2];

# include "ascii_screen.h"

t_pixel         get_julia_pixel(t_palette *palette, double x, double y, double c, double ci);
t_pixel         get_mandelbrot_pixel(t_palette *palette, double x, double y);

/*
**  MANDELBROT
**  requires a t_ascreen pixel map to write results on, and a t_palette for colorisation.
**  xoffset is the x point where you want to zoom in.
**  yoffset is the y point where you want to zoom in.
**  zoom is the zoom factor.
*/
void            mandelbrot(t_ascreen *screen, t_palette *palette, double xoffset, double yoffset, double zoom);

/*
**  JULIA
**  require same vars as mandelbrot.
**  adds the julia complex variable c = a + bi where c = a and ci = bi
*/
void            julia(t_ascreen *screen, t_palette *palette, double xoffset, double yoffset, double c, double ci, double zoom);

#endif