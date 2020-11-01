
#include "ascii_palette.h"



t_palette      *make_palette(char *ascii, t_pixel *colors, size_t c_len)
{
    t_palette  *palette;
    int         i;
    int         len = ft_strlen(ascii);
    int         color_len = c_len / sizeof(t_pixel);

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
    static t_pixel blue_magenta_colors[] = { { .value = HWHITE }, { .value = HWHITE }, { .value = HWHITE }, { .value = HWHITE }, { .value = HCYAN }, { .value = CYAN }, { .value = HBLUE }, { .value = BLUE }, { .value = BLACK },  { .value = HWHITE }, { .value = HWHITE }, { .value = HWHITE }, { .value = HWHITE }, { .value = HMAGENTA }, { .value = MAGENTA }, { .value = HRED }, { .value = RED }, { .value = BLACK } };
    static t_pixel blue_white_colors[] = { { .value = HBLUE }, { .value = HBLUE }, { .value = HBLUE }, { .value = HBLUE }, { .value = HBLUE },  { .value = HCYAN }, { .value = HCYAN }, { .value = HCYAN }, { .value = HWHITE }, { .value = HWHITE }, { .value = HYELLOW }, { .value = HYELLOW }, { .value = HYELLOW }, { .value = HYELLOW }, { .value = HYELLOW }, { .value = HYELLOW }, { .value = HYELLOW }, { .value = YELLOW }, { .value = YELLOW }, { .value = YELLOW }, { .value = YELLOW }, { .value = YELLOW } };
    static t_pixel black_magenta_colors[] = { { .value = BLACK }, { .value = BLACK }, { .value = BLACK }, { .value = MAGENTA }, { .value = MAGENTA }, { .value = HMAGENTA }, { .value = HMAGENTA }, { .value = HMAGENTA }, { .value = HWHITE }, };
    static t_pixel red_yellow_colors[] = { { .value = BLACK }, { .value = BLACK }, { .value = BLACK }, { .value = RED }, { .value = RED }, { .value = HRED }, { .value = HRED }, { .value = YELLOW }, { .value = HWHITE } };
    static t_pixel yellow_black_colors[] = { { .value = BLACK }, { .value = BLACK }, { .value = BLACK }, { .value = HBLACK }, { .value= HWHITE }, { .value = HYELLOW }, { .value = HYELLOW }, { .value = YELLOW } };
    static t_pixel black_rainbow_colors[] = { {.value = BLACK }, { .value = HBLACK }, { .value = MAGENTA }, { .value = HMAGENTA }, { .value = HYELLOW },  { .value = YELLOW }, {.value = HBLUE }, { .value = HCYAN }, { .value = GREEN }, { .value = HGREEN }, { .value = HYELLOW },  { .value = YELLOW } };
    static t_pixel blue_red_colors[] = { {.value = BLACK }, {.value = BLACK }, {.value = BLACK }, { .value = HYELLOW }, { .value = YELLOW }, { .value = HYELLOW }, { .value = YELLOW }, { .value = HYELLOW }, { .value = HRED },  { .value = RED }, {.value = CYAN }, { .value = HCYAN }, { .value = BLUE }, { .value = HBLUE }, { .value = HYELLOW },  { .value = HCYAN }, { .value = BLACK }, { .value = BLACK }, { .value = BLACK }, { .value = BLACK }, { .value = BLACK }, { .value = BLACK }, { .value = BLACK }, { .value = BLACK } };
    static t_pixel red_yellow_green_colors[] = { {.value = RED }, {.value = RED }, {.value = RED }, { .value = HYELLOW }, { .value = HYELLOW }, { .value = HYELLOW }, { .value = HGREEN }, { .value = HGREEN }, { .value = HGREEN } };


    switch (palette_ID)
    {
        case GRAYSCALE_P :
            return (make_palette("@#W&|%<>/};*^~,.", grayscale_colors, sizeof(grayscale_colors)));
        case RAINBOW_P :
            return (make_palette("$@B%8&WM#*oahkbdpq/|()1{}[]?-_+~<>i!lI;:,\"^`'. ", rainbow_colors, sizeof(rainbow_colors)));
        case BLUE_MAGENTA_P :
            return (make_palette("#@$&8pfgo*^;,. #@$&8pfgo*^;,. ", blue_magenta_colors, sizeof(blue_magenta_colors)));
        case BLUE_WHITE_P :
            return (make_palette("@#WB&MGHXEFYUVLJIO%hkgdmnaoui/};~,.  ", blue_white_colors, sizeof(blue_white_colors)));
        case BLACK_MAGENTA_P :
            return (make_palette("***********************************************************************", black_magenta_colors, sizeof(black_magenta_colors)));
        case RED_YELLOW_P :
            return (make_palette("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'. ", red_yellow_colors, sizeof(red_yellow_colors)));
        case YELLOW_P :
            return (make_palette("$@#Ss?!){}><=+;,. ", yellow_black_colors, sizeof(yellow_black_colors)));
        case BLACK_RAINBOW_P :
            return (make_palette("$@B%8&WM#*oahkbdpq/|()1{}[]?-_+~<>i!lI;:,\"^`'. ", black_rainbow_colors, sizeof(black_rainbow_colors)));
        case RED_YELLOW_GREEN_P :
            return (make_palette("$@#Ss?!){}><=+;,. ", red_yellow_green_colors, sizeof(red_yellow_green_colors)));
        case BLUE_RED_P :
            return (make_palette("$@B%8&WM#*oahkbdpq/|()1{}[]?-_+~<>i!lI;:,\"^`'. $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$", blue_red_colors, sizeof(blue_red_colors)));
        
        default :
            return (NULL);
    }
}

void        palette_free(t_palette *palette)
{
    free(palette->pixels);
    free(palette);
}

