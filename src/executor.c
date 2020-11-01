
#include "fractals.h"


void exec_mandelbrot(t_palette *palette, float zoom_factor, double x, double y)
{
    t_ascreen   *screen = NULL;
    float       init_zoom = 1.3f;
    float       zoom = init_zoom;
    long        actual_ms, target_ms;

    create_screen(&screen, RES[0], RES[1]);
    double max = MAX(screen->size_x / 2.0f, screen->size_y);
    double min = MIN(screen->size_x / 2.0f, screen->size_y);
    if (max == screen->size_x / 2.0f)
    {
        DEF_X[0] = -2.0f;
        DEF_X[1] =  2.0f;
        DEF_Y[0] = -2.0f * (min / max);
        DEF_Y[1] =  2.0f * (min / max);
    }
    else
    {
        DEF_X[0] = -2.0f * (min / max);
        DEF_X[1] =  2.0f * (min / max);
        DEF_Y[0] = -2.0f;
        DEF_Y[1] =  2.0f;
    }

    int unblocked_fd = 0;
    char input_buffer[BUFFER_LEN];

    while (1)
    {
        mandelbrot(screen, palette, x, y, zoom);
        print_screen(screen);
        ft_putstr("\033[1;37mAppuie sur Entree pour pauser la simulation.\033[0m");
        zoom *= 1 + zoom_factor;
        //Waiting for fps cap (Note that it can lag due to previous iterations in mandelbrot())
        target_ms = clock() + FRAME_TIME_MS;
        actual_ms = clock();
        while (actual_ms < target_ms)
            actual_ms = clock();
        unblock_read(&unblocked_fd);
        if (read(unblocked_fd, input_buffer, BUFFER_LEN) > 0)
        {
            if (input_buffer[0] == 10)
            {
                ft_putstr("\r\033[1;37mSimulation Stop.\033[0m Que voulez vous faire ?          \n 1 - continuer\n 2 - recommencer\n 3 - inverser zoom\n 4 - nouvelle fractale\n 5 - quitter\n");
                block_read(&unblocked_fd);
                if (request_input(input_buffer))
                {
                    switch (input_buffer[0] - '0')
                    {
                        case 1 :
                            break;
                        case 2 :
                            zoom = init_zoom;
                            zoom_factor = abs_d(zoom_factor);
                            break;
                        case 3 :
                            zoom_factor = -zoom_factor;
                            break;
                        case 4 :
                            palette_free(palette);
                            destroy_screen(screen);
                            return ;
                            break;
                        case 5 :
                            palette_free(palette);
                            destroy_screen(screen);
                            exit(0);
                            break;
                        default :
                            ft_putstr("Unhandled input.\n");
                            break;
                    }
                }
            }
        }
        block_read(&unblocked_fd);
    }
    destroy_screen(screen);
}



void exec_julia(t_palette *palette, float zoom_factor, double x, double y, double c, double ci)
{
    t_ascreen   *screen = NULL;
    float       init_zoom = 1.3f;
    float       iterator = 0, m_c = 0, m_ci = 0.5f, zoom = init_zoom;
    long        actual_ms, target_ms;

    create_screen(&screen, RES[0], RES[1]);
    double max = MAX(screen->size_x / 2.0f, screen->size_y);
    double min = MIN(screen->size_x / 2.0f, screen->size_y);
    if (max == screen->size_x / 2.0f)
    {
        DEF_X[0] = -2.0f;
        DEF_X[1] =  2.0f;
        DEF_Y[0] = -2.0f * (min / max);
        DEF_Y[1] =  2.0f * (min / max);
    }
    else
    {
        DEF_X[0] = -2.0f * (min / max);
        DEF_X[1] =  2.0f * (min / max);
        DEF_Y[0] = -2.0f;
        DEF_Y[1] =  2.0f;
    }

    int unblocked_fd = 0;
    char input_buffer[BUFFER_LEN];

    while (1)
    {
        iterator+=5;
        m_c = ft_sin(iterator);
        m_ci = m_c + 0.5f;
        if (c != MULTI_J && ci != MULTI_J)
            julia(screen, palette, x, y, c, ci, zoom);
        else
            julia(screen, palette, x, y, m_c, m_ci, zoom);
        print_screen(screen);
        ft_putstr("\033[1;37mAppuie sur Entree pour pauser la simulation.\033[0m");
        zoom *= 1 + zoom_factor;
        //Waiting for fps cap (Note that it can lag due to previous iterations in julia())
        target_ms = clock() + FRAME_TIME_MS;
        actual_ms = clock();
        while (actual_ms < target_ms)
            actual_ms = clock();
        unblock_read(&unblocked_fd);
        if (read(unblocked_fd, input_buffer, BUFFER_LEN) > 0)
        {
            if (input_buffer[0] == 10)
            {
                ft_putstr("\r\033[1;37mSimulation Stop.\033[0m Que voulez vous faire ?        \n 1 - continuer\n 2 - recommencer\n 3 - inverser zoom\n 4 - nouvelle fractale\n 5 - quitter\n");
                block_read(&unblocked_fd);
                if (request_input(input_buffer))
                {
                    switch (input_buffer[0] - '0')
                    {
                        case 1 :
                            break;
                        case 2 :
                            zoom = init_zoom;
                            zoom_factor = abs_d(zoom_factor);
                            break;
                        case 3 :
                            zoom_factor = -zoom_factor;
                            break;
                        case 4 :
                            palette_free(palette);
                            destroy_screen(screen);
                            return ;
                            break;
                        case 5 :
                            palette_free(palette);
                            destroy_screen(screen);
                            exit(0);
                            break;
                        default :
                            ft_putstr("Unhandled input.\n");
                            break;
                    }
                }
            }
        }
        block_read(&unblocked_fd);
    }
    destroy_screen(screen);
}


