
#ifndef ASCII_SCREEN
# define ASCII_SCREEN

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "ascii_palette.h"

# define DEFAULT_CLEAR	'X'

typedef struct	s_ascreen
{
    uint16_t	size_x;
	uint16_t	size_y;
	uint8_t		*pixels;
}				t_ascreen;

int     create_screen(t_ascreen **screen, uint16_t sx, uint16_t sy);
void    set_pixel(t_ascreen *screen, uint16_t x, uint16_t y, char value);
void    print_screen(const t_ascreen *screen);
void	print_screen_palette(const t_ascreen *screen, const t_palette palette);
void	destroy_screen(t_ascreen *screen);

#endif