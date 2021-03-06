
#ifndef ASCII_SCREEN
# define ASCII_SCREEN

# include "ascii_palette.h"

# define DEFAULT_CLEAR	WHITE
# define FRAME_TIME_MS	120000

typedef struct	s_ascreen
{
    uint16_t	size_x;
	uint16_t	size_y;
	t_pixel		*data;
	t_pixel		*pixels;
	size_t		screen_sz;
}				t_ascreen;

int     create_screen(t_ascreen **screen, uint16_t sx, uint16_t sy);
void    set_pixel(t_ascreen *screen, uint16_t x, uint16_t y, t_pixel value);
void    print_screen(const t_ascreen *screen);
void	destroy_screen(t_ascreen *screen);

#endif