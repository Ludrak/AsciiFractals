
#include "ascii_palette.h"
#include "ascii_screen.h"
#include "mandelbrot.h"
#include "stdio.h"
#include "time.h"

#define CONSOLE_CLEAR_ANSI "\e[1;1H\e[2J"

int main()
{
    t_ascreen *screen = NULL;
    t_palette palette = "@#%$&wxvi+;:,. #%$&wxvi+;:,. %$&wxvi+;:,. $&wxvi+;:,. &wxvi+;:,. wxvi+;:,. xvi+;:,. vi+;:,. i+;:,. +;:,. ;:,. :,. ,. .  ";//" .,:ilwWHJFKDHJKHKLDFHHJKFHDJKFHJKDHFHDJKFHKJDHFK";//"#@&+.@&+.&+.+..";//{'#', '@', '&', '+', '.'};
    double    zoom = 1;
    
    create_screen(&screen, 180, 60);
    //print_screen(screen);
    while (1)
    {
        mandelbrot(screen, palette, -0.2, 0, zoom);
        write(1, CONSOLE_CLEAR_ANSI, sizeof(CONSOLE_CLEAR_ANSI));
        print_screen(screen);
       // zoom += 1.00000000002f;
        usleep(100000);
    }
    destroy_screen(screen);
    return (0);
}