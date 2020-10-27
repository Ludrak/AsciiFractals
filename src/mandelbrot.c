
#include <math.h>
#include "mandelbrot.h"

char    get_mandelbrot_pixel(t_palette palette, double x, double y, double zoom)
{
    (void)zoom;
    int iterations = 0;
    double x_square, y_square, x0 = x, y0 = y;

    while (iterations < MAX_ITERATIONS)
    {
        x_square = x * x - y * y;
        y_square = 2 * x * y;
        x = x_square + x0;
        y = y_square + y0;

        if (abs_d(x + y) > M_INFINITY)    
        {
            int brightness = (int)map_d(iterations - logf(log2f(abs_d(x + y))), 0, MAX_ITERATIONS  / (MAX_ITERATIONS / 32), 0, palette_len(palette));
            if (palette && palette[brightness] > 32)
                return (palette[brightness % palette_len(palette)]);
            else
                return ('.');
        }
        iterations++;
    }
    return (' ');
}

void    mandelbrot(t_ascreen *screen, t_palette palette, double xoffset, double yoffset, double zoom)
{
    int x = 0, y = 0;

    while (y < screen->size_y)
    {
        x = 0;
        while (x < screen->size_x)
        {
            double mx = map_d(x, 0, screen->size_x, -2 / zoom, 2 / zoom) + xoffset;
            double my = map_d(y, 0, screen->size_y, -1.3f / zoom, 1.3f / zoom) - yoffset;
            screen->pixels[x + y * screen->size_x] = get_mandelbrot_pixel(palette, mx, my, zoom);
            x++;
        }
        y++;
    }
}