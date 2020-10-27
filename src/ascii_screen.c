
#include "ascii_screen.h"

int     create_screen(t_ascreen **screen, uint16_t sx, uint16_t sy)
{
    int i = 0;

    if (!(*screen = malloc(sizeof(t_ascreen))))
        return (-1);
    (*screen)->size_x = sx;
    (*screen)->size_y = sy;
    if (!((*screen)->pixels = malloc(sizeof(*(*screen)->pixels) * (sx * sy))))
        return (-1);
    while (i < sx * sy)
        (*screen)->pixels[i++] = DEFAULT_CLEAR;
    return (0);
}

void    set_pixel(t_ascreen *screen, uint16_t x, uint16_t y, char value)
{
    screen->pixels[x + y * screen->size_x] = value;
}

void    print_screen(const t_ascreen *screen)
{
    uint16_t y = 0;

    if (!screen || !screen->pixels)
        return ;
    while (y < screen->size_y)
    {
        write(1, screen->pixels + y * screen->size_x, screen->size_x);
        write(1, "\n", 1);
        y++;
    }
}

void    destroy_screen(t_ascreen *screen)
{
    free(screen->pixels);
    free(screen);
}