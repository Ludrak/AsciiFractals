
#ifndef MANDELBROT_H
# define MANDELBROT_H

# define MAX_ITERATIONS 100000
# define M_INFINITY       100000

# include "ascii_screen.h"

t_pixel         get_mandelbrot_pixel(t_palette2 *palette, double x, double y, double zoom);
void            mandelbrot(t_ascreen *screen, t_palette2 *palette, double xoffset, double yoffset, double zoom);

#endif