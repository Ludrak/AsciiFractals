
#include "ascii_screen.h"

int     create_screen(t_ascreen **screen, uint16_t sx, uint16_t sy)
{
    if (!(*screen = malloc(sizeof(t_ascreen))))
        return (-1);
    (*screen)->size_x = sx + 1;
    (*screen)->size_y = sy;
    if (!((*screen)->pixels = malloc(sizeof(*(*screen)->pixels) * ((sx + 1) * sy))))
        return (-1);
    return (0);
}

void    set_pixel(t_ascreen *screen, uint16_t x, uint16_t y, t_pixel pixel)
{
    screen->pixels[x + y * screen->size_x] = pixel;
}

void    print_screen(const t_ascreen *screen)
{
    if (!screen || !screen->pixels)
        return ;
    write(1, CLR_ANSI, sizeof(CLR_ANSI));
    write(1, screen->pixels, (screen->size_x * screen->size_y) * sizeof(*screen->pixels));
}

void    destroy_screen(t_ascreen *screen)
{
    free(screen->pixels);
    free(screen);
}