
#include "utils.h"

long double  map_d(long double value, long double min1, long double max1, long double min2, long double max2)
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

int     ft_strncmp(const char *s1, const char *s2, size_t len)
{
        while (*s1 && *s2 && *s1 == *s2 && len--)
        {
                s1++;
                s2++;
        }
        return ((len == 0) ? 0 : (unsigned char)*s1 - *s2);
}

static int      ft_isdigit(int c)
{
        if (c >= '0' && c <= '9')
                return (1);
        return (0);
}

static int      ft_isspace(char c)
{
        return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int                     ft_atoi(const char *nptr)
{
        int                             sign;
        unsigned long   num;
        unsigned long   max;

        sign = 1;
        num = 0;
        while (ft_isspace(*nptr))
                nptr++;
        if (*nptr == '-' || *nptr == '+')
        {
                if (*nptr == '-')
                        sign = -1;
                nptr++;
        }
        max = sign < 0 ? 9223372036854775808UL : 9223372036854775807L;
        while (ft_isdigit(*nptr))
                num = (10 * num) + (*nptr++ - '0');
        if (num > max)
                return (sign < 0 ? 0 : -1);
        return (num * sign);
}

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
