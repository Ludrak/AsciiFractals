
#include "ascii_screen.h"

int     create_screen(t_ascreen **screen, uint16_t sx, uint16_t sy)
{
    static const char   header[64] = CLR_ANSI" > ASCII FRACTALS  -  by Ludrak\n";

    if (!(*screen = malloc(sizeof(t_ascreen))))
        return (-1);
    (*screen)->size_x = sx + 1;
    (*screen)->size_y = sy;
    (*screen)->screen_sz = sizeof(*(*screen)->data) * ((sx + 1) * sy) + sizeof(header);
    if (!((*screen)->data = malloc((*screen)->screen_sz)))
        return (-1);
    ft_memcpy((*screen)->data, header, sizeof(header));
    (*screen)->pixels = (*screen)->data + sizeof(header) / sizeof(*(*screen)->data);
    return (0);
}

void    set_pixel(t_ascreen *screen, uint16_t x, uint16_t y, t_pixel pixel)
{
    screen->pixels[x + y * screen->size_x] = pixel;
}

void    print_screen(const t_ascreen *screen)
{
    if (!screen || !screen->data)
        return ;
    write(1, screen->data, screen->screen_sz);
}

void    destroy_screen(t_ascreen *screen)
{
    free(screen->data);
    free(screen);
}