
#include "utils.h"

double  map_d(double value, double min1, double max1, double min2, double max2)
{
    return (min2 + (value - min1) * (max2 - min2) / (max1 - min1));
}

double  lerp(double a, double b, double f)
{
    return a + f * (b - a);
}

double  abs_d(double d)
{
    return ((d < 0) ? -d : d);
}

unsigned int    ft_strlen(char *str)
{
    unsigned int len = 0;

    while (str[len])
        len++;
    return (len);
}

void    ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}

int            request_input(char buffer[BUFFER_LEN])
{
    int nbytes;

    ft_putstr("> ");
    if ((nbytes = (int)read(0, buffer, BUFFER_LEN)) >= 0)
        return (nbytes);
    ft_putstr("Read error.");
    return (-1);
}

/*

void            ft_usleep(int ms)
{
    struct timeval  spec;
    long            actual_ms;
    long            target_ms;

    gettimeofday(&spec, NULL);
    actual_ms = (long)spec.tv_usec / 1000;
    target_ms = actual_ms + ms;
    while (1)
    {
        gettimeofday(&spec, NULL);
        actual_ms = (long)spec.tv_usec / 1000;
        if (actual_ms >= target_ms)
            break;
    }
}*/


void    *ft_memcpy(void *dst, const void *src, size_t n)
{
        unsigned char   *tmp;
        unsigned int    i;

        i = 0;
        tmp = (unsigned char *)dst;
        if (dst == src || !n)
                return (dst);
        while (i < (unsigned int)n)
        {
                *tmp = *(unsigned char *)(src + i);
                tmp++;
                i++;
        }
        return (dst);
}
