
#include "ascii_palette.h"

t_palette      *make_palette(char *ascii, t_pixel *colors, int color_len)
{
    t_palette  *palette;
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

t_palette  *load_palette(int palette_ID)
{    
    static t_pixel grayscale_colors[] = { { .value = HWHITE }, { .value = WHITE }, { .value = HBLACK } };
    static t_pixel rainbow_colors[] = { { .value = RED }, { .value = HRED }, { .value = YELLOW }, { .value = HYELLOW }, { .value = HGREEN }, { .value = GREEN }, { .value = HBLUE}, { .value = BLUE }, { .value = HMAGENTA }, { .value = MAGENTA} };
    static t_pixel red_colors[] = { { .value = RED }, { .value = HRED }, { .value = YELLOW }, { .value = HYELLOW }, { .value = BLACK } };
    static t_pixel red_blue_colors[] = { { .value = RED }, { .value = HRED }, { .value = MAGENTA }, { .value = HMAGENTA }, { .value = HBLUE }, { .value = BLUE }, { .value = BLACK } };

    t_palette  *palettes[] = {
        make_palette("@WBMGHXEFYUVLJIOhkgdmnaoui/};~,.", grayscale_colors, sizeof(grayscale_colors) / sizeof(*(grayscale_colors))),
        make_palette("@#WB&MGHXEFYUVLJIO%hkgdmnaoui/};~,.", rainbow_colors, sizeof(rainbow_colors) / sizeof(*(rainbow_colors))),
        make_palette("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'. ", red_colors, sizeof(red_colors) / sizeof(*(red_colors))),
        make_palette("@#%$&wxvi+;:,. #%$&wxvi+;:,. %$&wxvi+;:,. $wxvi+;:,. &i+;:,. :,. ", red_blue_colors, sizeof(red_blue_colors) / sizeof(*(red_blue_colors))),
        make_palette("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'. ", rainbow_colors, sizeof(rainbow_colors) / sizeof(*(rainbow_colors))),
        make_palette("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'. ", rainbow_colors, sizeof(rainbow_colors) / sizeof(*(rainbow_colors))),
        //make_palette("@#%$&wxvi+;:,. %$&wxvi+;:,. &wxvi+;:,. xvi+;:,. i+;:,. :,. ", rainbow_colors, sizeof(rainbow_colors) / sizeof(*(rainbow_colors))),
    };

    if (palette_ID >= 0 && palette_ID < 6)
        return (palettes[palette_ID]);
    return NULL;
}

