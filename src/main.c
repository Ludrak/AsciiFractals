
#include "ascii_palette.h"
#include "ascii_screen.h"
#include "fractals.h"
#include <time.h>

static void exec_mandelbrot(t_palette *palette, float zoom_factor, double x, double y)
{
    t_ascreen *screen = NULL;
    float zoom = 1.3f;
    long      actual_ms, target_ms;

    create_screen(&screen, 80, 40);
    while (1)
    {
        target_ms = clock() + FRAME_TIME_MS;
        actual_ms = clock();
        mandelbrot(screen, palette, x, y, zoom);
        print_screen(screen);
        (void)write (1, "\033[1;37mPress escape to exit.\033[0m\n", 28);
        zoom *= 1 + zoom_factor;
        //Waiting for fps cap (Note that it can lag due to previous iterations in mandelbrot())
        while (actual_ms < target_ms)
            actual_ms = clock();
    }
    destroy_screen(screen);
}



static void exec_julia(t_palette *palette, float zoom_factor, double x, double y, double c, double ci)
{
    t_ascreen   *screen = NULL;
    float       iterator = 0, m_c = 0, m_ci = 0.5f, zoom = 1.3f;
    long        actual_ms, target_ms;

    create_screen(&screen, 80, 40);
    while (1)
    {
        target_ms = clock() + FRAME_TIME_MS;
        actual_ms = clock();
        if (c != MULTI_J && ci != MULTI_J)
            julia(screen, palette, x, y, c, ci, zoom);
        else
            julia(screen, palette, x, y, m_c, m_ci, zoom);
        print_screen(screen);
        write (1, "\033[1;37mPress escape to exit.\n", 28);
        zoom *= 1 + zoom_factor;
        iterator+=5;
        m_c = ft_sin(iterator);
        m_ci = m_c + 0.5f;
        //Waiting for fps cap (Note that it can lag due to previous iterations in julia())
        while (actual_ms < target_ms)
            actual_ms = clock();
    }
    destroy_screen(screen);
}



static void mandelbrot_menu(int preset_id)
{
    char input_buffer[BUFFER_LEN];

    ft_putstr("Tu as choisi le Mandelbrot set !\n");
    ft_putstr("Choisis un preset pour l'execution de la fractale:\n");
    ft_putstr(" 1 - couleurs : GRAYSCALE   zoom : STATIQUE     position : CENTRE\n\
 2 - couleurs : RAINBOW     zoom : STATIQUE     position : CENTRE\n\
 3 - couleurs : GRAYSCALE   zoom : PROGRESSIF   position : (0, 1)\n\
 4 - couleurs : RAINBOW     zoom : PROGRESSIF   position : (0, 1)\n\
 5 - couleurs : RED         zoom : PROGRESSIF   position : (-1.5666, 0)\n\
 6 - couleurs : BLUE-RED    zoom : PROGRESSIF   position : (-0.235125, 0.827215)\n\
 7 - couleurs : RAINBOW     zoom : PROGRESSIF   position : (-0.235125, 0.827215)\n");
    while (request_input(input_buffer))
    {
        if (input_buffer[0])
        {
            preset_id = input_buffer[0] - '0';
            if (preset_id > 0 && preset_id <= 7)
                break;
            else
                ft_putstr("Tu dois choisir un preset valide !\n");
        }
    }
    ft_putstr("Preset OK, appuie sur Entrer pour commencer.");
    read(0, &input_buffer, 10);
    switch (preset_id)
    {
        case 1:
            exec_mandelbrot(load_palette(GRAYSCALE_P), 0.0f, 0, 0);
            break;
        case 2:
            exec_mandelbrot(load_palette(RAINBOW_P), 0.0f, 0, 0);
            break;
        case 3:
            exec_mandelbrot(load_palette(GRAYSCALE_P), 0.1f, 0, 1);
            break;
        case 4:
            exec_mandelbrot(load_palette(SKIN_WAVES), 0.1f, 0, 1);
            break;
        case 5:
            exec_mandelbrot(load_palette(RED_P), 0.1f, -1.56666, 0);
            break;
        case 6:
            exec_mandelbrot(load_palette(RED_BLUE_P), 0.1f, -0.235125, 0.827215);
            break;
        case 7:
            exec_mandelbrot(load_palette(RAINBOW_WAVES_P), 0.1f, -0.235125, 0.827215);
            break;
    }
}



static void    julia_menu(int preset_id)
{
    char    input_buffer[BUFFER_LEN];

    ft_putstr("Tu as choisi le Julia set !\n");
    ft_putstr("Choisis un preset pour l'execution de la fractale:\n");
    ft_putstr(" 1 - couleurs : GRAYSCALE   zoom : STATIQUE     position : CENTRE               julia : -0.038088 + 0.9754633i\n\
 2 - couleurs : RAINBOW     zoom : STATIQUE     position : CENTRE               julia : -0.038088 + 0.9754633i\n\
 3 - couleurs : RAINBOW     zoom : STATIQUE     position : CENTRE               julia : MULTI :)\n\
 4 - couleurs : BLUE-RED    zoom : PROGRESSIF   position : ~(-0.0028, 0.0030)   julia : -0.78 + 0.136i\n");
    while (request_input(input_buffer))
    {
        if (input_buffer[0])
        {
            preset_id = input_buffer[0] - '0';
            if (preset_id > 0 && preset_id <= 4)
                break;
            else
                ft_putstr("Tu dois choisir un preset valide !\n");
        }
    }
    ft_putstr("Preset OK, appuie sur Entrer pour commencer.");
    read(0, input_buffer, 10);
    switch (preset_id)
    {
        case 1:
            exec_julia(load_palette(GRAYSCALE_P), 0, 0, 0, -0.038088f, 0.9754633f);
            break;
        case 2:
            exec_julia(load_palette(RAINBOW_WAVES_P), 0, 0, 0, -0.8, 0.156);
            break;
        case 3:
            exec_julia(load_palette(RAINBOW_WAVES_P), 0, 0, 0, MULTI_J, MULTI_J);
            break;
        case 4:
            exec_julia(load_palette(RED_BLUE_P), 0.1f, 0, 0.25, -0.78, 0.136);
            break;
    }
}



int     main(void)
{
    char        input_buffer[BUFFER_LEN];
    int         fractal_id = 0;
    int         preset_id = 0;

    write(1, CLR_ANSI, sizeof(CLR_ANSI));
    ft_putstr(">>> Bienvenue sur Ascii Fractals !\nQuelles fractales souhaite tu realiser ? (Mandelbrot: 1, Julia: 2)\n");
    while (request_input(input_buffer))
    {
        if (input_buffer[0])
        {
            fractal_id = input_buffer[0] - '0';
            if (fractal_id == 1 || fractal_id == 2)
                break;
            else
                ft_putstr("Tu dois choisir entre 1 et 2 !\n");
        }
    }
    write(1, CLR_ANSI, sizeof(CLR_ANSI));

    if (fractal_id == 1)
        mandelbrot_menu(preset_id);
    if (fractal_id == 2)
        julia_menu(preset_id);
    return (0);
}
