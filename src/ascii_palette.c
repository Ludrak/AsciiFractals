
#include "ascii_palette.h"

unsigned int    palette_len(t_palette palette)
{
    unsigned int    len = 0;

    while(palette[len])
        len++;
    return (len);
}

void            print_palette(const t_palette palette, unsigned int index)
{
    write(1, palette + index, sizeof(palette));
}
