
#ifndef MANDELBROT_H
# define MANDELBROT_H

# define MAX_ITERATIONS 10000
# define M_INFINITY       100

# include "ascii_screen.h"
# include "utils.h"

char            get_mandelbrot_pixel(t_palette palette, double px, double py, double zoom);
void            mandelbrot(t_ascreen *screen, t_palette palette, double xoffset, double yoffset, double zoom);

#endif