
#include "ascii_palette.h"
#include "ascii_screen.h"
#include "fractals.h"
# include <signal.h>

#include <stdio.h>


struct sigaction    old;

long double DEF_X[2] = {-2, 2};
long double DEF_Y[2] = {-2, 2};
int         RES[2] = {80, 40};
int         MAX_ITER = 10000;


void    exit_handler(int sig);


static void mandelbrot_menu(int preset_id)
{
    char input_buffer[BUFFER_LEN];

    ft_putstr("Tu as choisi le Mandelbrot set !\n");
    ft_putstr("Choisis un preset pour l'execution de la fractale:\n");
    ft_putstr(" 1 - couleurs : GRAYSCALE      zoom : STATIQUE     position : (-0.5, 0)\n\
 2 - couleurs : BLUE-WHITE     zoom : STATIQUE     position : (-0.5, 0)\n\
 3 - couleurs : BLACK-MAGENTA  zoom : PROGRESSIF   position : (0, 1)\n\
 4 - couleurs : WBLUE-WMAGENTA zoom : PROGRESSIF   position : (-0.56220, 0.642817)\n\
 5 - couleurs : RED-YELLOW     zoom : PROGRESSIF   position : (-1.5666, 0)\n\
 6 - couleurs : RAINBOW        zoom : PROGRESSIF   position : (-0.235125, 0.827215)\n\
 7 - couleurs : RAINBOW        zoom : PROGRESSIF   position : (-0.235125, 0.827215)\n");
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
            exec_mandelbrot(load_palette(GRAYSCALE_P), 0.0f, -0.5f, 0);
            break;
        case 2:
            exec_mandelbrot(load_palette(BLUE_WHITE_P), 0.0f, -0.5f, 0);
            break;
        case 3:
            exec_mandelbrot(load_palette(BLACK_MAGENTA_P), 0.1f,  0, -1);
            break;
        case 4:
        // -0.56218f, 0.642816f
        // 2:  -0.56217701535f, 0.6428130351f

        //-0.56217701535
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
            exec_julia(load_palette(BLUE_WHITE_P), 0, 0, 0, -0.8, 0.156);
            break;
        case 3:
            exec_julia(load_palette(RAINBOW_P), 0, 0, 0, MULTI_J, MULTI_J);
            break;
        case 4:
            exec_julia(load_palette(BLUE_MAGENTA_P), 0.1f, 0, 0.25, -0.78, 0.136);
            break;
    }
}



void    main_menu(void)
{
    char                input_buffer[BUFFER_LEN];
    int                 fractal_id = 0;
    int                 preset_id = 0;

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
}



void    exit_handler(int sig)
{
    sigset_t    set;
    char        input_buffer[BUFFER_LEN];

    (void)sig;
    signal(SIGINT, exit_handler);
    sigemptyset(&set);
    sigprocmask(SIG_SETMASK, &set, NULL);
    ft_putstr(CLR_ANSI"Simulation stop.\nVeux tu relancer une autre fractale ? (Y/N):\n");
    while (request_input(input_buffer))
    {
        char    ans = input_buffer[0];
        if (ans == 'y' || ans == 'Y')
            main_menu();
        else if (ans == 'n' || ans == 'N')
            break;
        else
            ft_putstr("Tu dois choisir entre Y et N.\n");
    }
    exit(0);
}



int     main(int ac, char **av)
{
    //struct sigaction    act;
    int                 i = 1;

    //.sa_sigaction = &exit_handler;
    //act.sa_flags = SA_SIGINFO;
    //sigaction(SIGINT, &act, &old);
    signal(SIGINT, exit_handler);
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
