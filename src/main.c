
#include "ascii_palette.h"
#include "ascii_screen.h"
#include "fractals.h"

long double DEF_X[2] = {-2, 2};
long double DEF_Y[2] = {-2, 2};
int         RES[2] = {40, 20};
int         MAX_ITER = 100;


static void mandelbrot_menu(int preset_id)
{
    char input_buffer[BUFFER_LEN];

    ft_putstr("\033[1;37m# Tu as choisi le Mandelbrot set !\033[0;37m\n");
    ft_putstr("# Choisis un preset pour l'execution de la fractale:\n");
    ft_putstr("# 1 - couleurs : GRAYSCALE      zoom : STATIQUE     position : (-0.5, 0)\n\
# 2 - couleurs : BLUE-WHITE     zoom : STATIQUE     position : (-0.5, 0)\n\
# 3 - couleurs : BLACK-MAGENTA  zoom : PROGRESSIF   position : (0, 1)\n\
# 4 - couleurs : WBLUE-WMAGENTA zoom : PROGRESSIF   position : (-0.56217671787, 0.642816)\n\
# 5 - couleurs : RED-YELLOW     zoom : PROGRESSIF   position : (-1.5666, 0)\n\
# 6 - couleurs : RAINBOW        zoom : PROGRESSIF   position : (-1.40244, 0)\n\
# 7 - couleurs : BLACK-YELLOW   zoom : PROGRESSIF   position : (0.41020942285, -0.30946)\n");
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
    ft_putstr("Appuie sur Entrer pour commencer.");
    read(0, &input_buffer, 10);
    switch (preset_id)
    {
        case 1:
            exec_mandelbrot(load_palette(GRAYSCALE_P), 0.0f, -0.5f, 0);
            break;
        case 2:
            exec_mandelbrot(load_palette(BLUE_WHITE_P), 0.0f, -0.5f, 0);
            break;
        case 3:
            exec_mandelbrot(load_palette(BLACK_MAGENTA_P), 0.1f,  0, -1);
            break;
        case 4:
            exec_mandelbrot(load_palette(BLUE_MAGENTA_P), 0.1f,   -0.56217671787f, 0.642816f);
            break;
        case 5:
            exec_mandelbrot(load_palette(RED_YELLOW_P), 0.1f, -1.56666, 0);
            break;
        case 6:
            exec_mandelbrot(load_palette(RAINBOW_P), 0.1f, -1.40244f, 0);
            break;
        case 7:
            exec_mandelbrot(load_palette(YELLOW_P), 0.1f, 0.41020942285f, -0.30946f);
            break;
    }
}



static void    julia_menu(int preset_id)
{
    char    input_buffer[BUFFER_LEN];

    ft_putstr("\033[1;37m# Tu as choisi le Julia set !\033[0;37m\n");
    ft_putstr("# Choisis un preset pour l'execution de la fractale:\n");
    ft_putstr("# 1 - couleurs : GRAYSCALE      zoom : STATIQUE     position : CENTRE               julia : -0.038088 + 0.9754633i\n\
# 2 - couleurs : BLACK RAINBOW  zoom : STATIQUE     position : (-0.1314, 0.1)       julia : 0.285 + 0.01i\n\
# 3 - couleurs : RAINBOW        zoom : STATIQUE     position : CENTRE               julia : MULTI :)\n\
# 4 - couleurs : RED YEL. GREEN zoom : LENT         position : ~(-0.0025, 0.15)     julia : -0.7269 + 0.1888i\n\
# 5 - couleurs : BLUE RED       zoom : LENT         position : ~(-0.0025, 0.15)     julia : -0.4 + 0.6i\n\
# 6 - couleurs : BLU. YEL. WHIT.zoom : PROGRESSIF   position : (0, 0.25)            julia : -0.78 + 0.136i\n\
# 7 - couleurs : BLACK RAINBOW  zoom : LENT         position : (0, 0)               julia : -1.476\n");
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
    ft_putstr("Appuie sur Entrer pour commencer.");
    read(0, input_buffer, 10);
    switch (preset_id)
    {
        case 1:
            exec_julia(load_palette(GRAYSCALE_P), 0, 0, 0, -0.038088f, 0.9754633f);
            break;
        case 2:
            exec_julia(load_palette(BLACK_RAINBOW_P), 0.01f, -0.1314f, 0.1f, 0.285f, 0.01f);
            break;
        case 3:
            exec_julia(load_palette(RAINBOW_P), 0, 0, 0, MULTI_J, MULTI_J);
            break;
        case 4:
            exec_julia(load_palette(RED_YELLOW_GREEN_P), 0.1f, -0.0025003f, 0.15f,  -0.7269f, 0.1888f);
            break;

        case 5:
            exec_julia(load_palette(BLUE_RED_P), 0.01f, -0.0025003f, 0.15f,  -0.4f, 0.6f);
            break;

        case 6:
            exec_julia(load_palette(BLUE_WHITE_P), 0.1f, 0, 0.25f,  -1.476f, 0);
            break;

        case 7:
            exec_julia(load_palette(BLACK_RAINBOW_P), 0.01f, 0, 0,  -0.54f, 0.54f);
            break;
    }
}



void    main_menu(void)
{
    char                input_buffer[BUFFER_LEN];
    int                 fractal_id = 0;
    int                 preset_id = 0;

    write(1, CLR_ANSI, sizeof(CLR_ANSI));
    ft_putstr("\033[1;37m# Bienvenue sur Ascii Fractals !\n\033[0;37m# Quelles fractales souhaite tu realiser ? (Mandelbrot: 1, Julia: 2)\n");
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
    main_menu();
}



int     main(int ac, char **av)
{
    int                 i = 1;

    if (ac > 1)
    {
        while (i < ac)
        {
            if (ft_strncmp(av[i], "res=", 4) == 0)
            {
                RES[0] = ft_atoi(av[i] + 4) * 2;
                while (av[i] && *(av[i] - 1) != 'x')
                    av[i]++;
                RES[1] = ft_atoi(av[i]);
                if (RES[0] <= 0 || RES[1] <= 0)
                {
                    ft_putstr("Invalid resolution parameters.\n");
                    return (-1);
                }
            }
            else if (ft_strncmp(av[i], "max_iter=", 9) == 0)
            {
                MAX_ITER = ft_atoi(av[i] + 9);
                if (MAX_ITER <= 0)
                {
                    ft_putstr("Iterations cannot be zero or negative.\n");
                    return (-1);
                }
            }
            else
            {
                ft_putstr("Invalid input parameters. Exit.\n");
                return (-1);
            }
            i++;
        }
    }
    main_menu();
    return (0);
}
