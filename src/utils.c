
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

double  log_d(double d)
{
    return (d * d * d * d * d * d * d * d * d * d);
}

double  log2_d(double d)
{
    return (d * d);
}

unsigned int    ft_strlen(char *str)
{
    unsigned int len = 0;

    while (str[len])
        len++;
    return (len);
}