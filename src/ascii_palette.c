
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

t_palette2      *make_palette(char *ascii, t_pixel *colors, int color_len)
{
    t_palette2  *palette;
    int         i;
    int         len = ft_strlen(ascii);

    if (!(palette = malloc(sizeof(*palette))))
        return (NULL);
    palette->len = len;
    if (!(palette->pixels = malloc(len * sizeof(*palette->pixels))))
        return (NULL);
    i = 0;
    while (i < len)
    {
        palette->pixels[i] = colors[i % color_len];
        palette->pixels[i].value[7] = ascii[i];
        i++;
    }
    return (palette);
}

