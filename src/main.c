
#include "ascii_palette.h"
#include "ascii_screen.h"
#include "mandelbrot.h"
#include "stdio.h"
#include "time.h"

int main()
{
    t_ascreen *screen = NULL;
   // t_palette palette = "@#%$&wxvi+;:,. #%$&wxvi+;:,. %$&wxvi+;:,. $&wxvi+;:,. &wxvi+;:,. wxvi+;:,. xvi+;:,. vi+;:,. i+;:,. +;:,. ;:,. :,. ,. .  ";//" .,:ilwWHJFKDHJKHKLDFHHJKFHDJKFHJKDHFHDJKFHKJDHFK";//"#@&+.@&+.&+.+..";//{'#', '@', '&', '+', '.'};

    t_pixel colors[] = {
        { .value = BLACK } ,
        { .value = HBLACK} ,
        { .value = RED } ,
        { .value = HRED } ,
        { .value = YELLOW } ,
        { .value = HYELLOW } ,
        { .value = GREEN } ,
        { .value = HGREEN } ,
        { .value = CYAN } ,
        { .value = HCYAN } ,
        { .value = BLUE } ,
        { .value = HBLUE } ,
        { .value = MAGENTA } ,
        { .value = HMAGENTA } 
    };


    t_palette2 *p2 = make_palette("@#%$&wxvi+;:,. #%$&wxvi+;:,. %$&wxvi+;:,. $&wxvi+;:,. &wxvi+;:,. wxvi+;:,. xvi+;:,. vi+;:,. i+;:,. +;:,. ;:,. :,. ,. .  ", colors, sizeof(colors) / sizeof(*colors));

    double    zoom = 0.5;
    
    create_screen(&screen, 180, 60);
    //print_screen(screen);
    while (1)
    {
        mandelbrot(screen, p2, 0, 1, zoom);
        print_screen(screen);
        zoom *= 1.01f;
        usleep(100000);
    }
    destroy_screen(screen);
    return (0);
}