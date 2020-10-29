
#ifndef ASCII_PALETTE_H
# define ASCII_PALETTE_H

# include <stdlib.h>
# include <stdint.h>
# include "utils.h"

#define COLOR_SIZE 8


typedef union   u_pixel
{
    uint8_t     value[8];
    uint64_t    color;
}               t_pixel;

typedef struct  s_palette2
{
    t_pixel     *pixels;
    size_t      len;
}               t_palette;

#define ENDL        "\n\0\0\0\0\0\0\0"
#define CLR_ANSI    "\e[1;1H\e[2J"

#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define HBLACK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGREEN "\e[0;92m"
#define HYELLOW "\e[0;93m"
#define HBLUE "\e[0;94m"
#define HMAGENTA "\e[0;95m"
#define HCYAN "\e[0;96m"
#define HWHITE "\e[0;97m"

t_palette      *make_palette(char *ascii, t_pixel *colors, int color_len);

# define GRAYSCALE_P        0
# define RAINBOW_P          1
# define RED_P              2
# define RED_BLUE_P         3
# define RAINBOW_WAVES_P    4
# define SKIN_WAVES         5
t_palette      *load_palette(int palette_ID);

#endif