
#include "fractals.h"

t_pixel    get_julia_pixel(t_palette *palette, long double x, long double y, double c, double ci)
{
    int iterations = 0;
    double x_square, y_square;

    while (iterations < MAX_ITER)
    {
        x_square = x * x - y * y;
        y_square = 2 * x * y;
        x = x_square + c;
        y = y_square + ci;

        if (abs_d(x + y) > M_INFINITY)    
        {
            int brightness = (int)map_d(iterations - log_d((double)msb(abs_d(x + y))), 0, palette->len, 0, palette->len);
            if (palette && brightness >= 0)
                return (palette->pixels[brightness % palette->len]);
            else
                return (palette->pixels[0]);
        }
        iterations++;
    }
    return ((t_pixel){ .value=BLACK"#" });
}

void    julia(t_ascreen *screen, t_palette *palette, double xoffset, double yoffset, double c, double ci, double zoom)
{
    int x = 0, y = 0;

    while (y < screen->size_y)
    {
        x = 0;
        while (x < screen->size_x)
        {
            long double mx = map_d(x, 0, screen->size_x, DEF_X[0] / zoom, DEF_X[1] / zoom) + xoffset;
            long double my = map_d(y, 0, screen->size_y, DEF_Y[0] / zoom, DEF_Y[1] / zoom) - yoffset;
            screen->pixels[x + y * screen->size_x] = get_julia_pixel(palette, mx, my, c, ci);
            x++;
        }
        screen->pixels[screen->size_x - 1 + y *screen->size_x] = (t_pixel){ .value = ENDL };
        y++;
    }
}