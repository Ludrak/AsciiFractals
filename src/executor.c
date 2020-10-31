
#include "fractals.h"

void exec_mandelbrot(t_palette *palette, float zoom_factor, double x, double y)
{
    t_ascreen *screen = NULL;
    float zoom = 1.3f;
    long      actual_ms, target_ms;

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
    while (1)
    {
        target_ms = clock() + FRAME_TIME_MS;
        actual_ms = clock();
        mandelbrot(screen, palette, x, y, zoom);
        print_screen(screen);
        (void)write (1, "\033[1;37mPress escape to exit.\033[0m\n", 28);
        //printf("\nZOOM X: %.20Lf ZOOM Y: %.20Lf \n", DEF_X[1] / zoom, DEF_Y[1] / zoom);
        zoom *= 1 + zoom_factor;
        //Waiting for fps cap (Note that it can lag due to previous iterations in mandelbrot())
        while (actual_ms < target_ms)
            actual_ms = clock();
    }
    destroy_screen(screen);
}



void exec_julia(t_palette *palette, float zoom_factor, double x, double y, double c, double ci)
{
    t_ascreen   *screen = NULL;
    float       iterator = 0, m_c = 0, m_ci = 0.5f, zoom = 1.3f;
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


