
#include <math.h>
#include "fractals.h"
#include <math.h>
t_pixel    get_mandelbrot_pixel(t_palette *palette, long double x, long double y)
{
    int iterations = 0;
    double x_square, y_square, x0 = x, y0 = y;

    while (iterations < MAX_ITER)
    {
        x_square = x * x - y * y;
        y_square = 2 * x * y;
        x = x_square + x0;
        y = y_square + y0;

        if (abs_d(x + y) > M_INFINITY)    
        {
            int brightness = (int)map_d(iterations - log_d((double)msb(abs_d(x + y))), 0, MAX_ITER  / (MAX_ITER / 32), 0, palette->len);
            if (palette && brightness >= 0)
                return (palette->pixels[brightness % palette->len]);
            else
                return (palette->pixels[0]);
        }
        iterations++;
    }
    return ((t_pixel){ .value=BLACK"#" });
}

void    mandelbrot(t_ascreen *screen, t_palette *palette, double xoffset, double yoffset, double zoom)
{
    int x = 0, y = 0;

    while (y < screen->size_y)
    {
        x = 0;
        while (x < screen->size_x)
        {
            long double mx = map_d(x, 0, screen->size_x, DEF_X[0] / zoom, DEF_X[1] / zoom) + xoffset;
            long double my = map_d(y, 0, screen->size_y, DEF_Y[0] / zoom, DEF_Y[1] / zoom) - yoffset;
            screen->pixels[x + y * screen->size_x] = get_mandelbrot_pixel(palette, mx, my);
            x++;
        }
        screen->pixels[screen->size_x - 1 + y *screen->size_x] = (t_pixel){ .value = ENDL };
        y++;
    }
}