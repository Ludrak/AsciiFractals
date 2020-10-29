
#ifndef UTILS_H
# define UTILS_H

#include <unistd.h>
//#include <sys/time.h>

#define BUFFER_LEN 8

double          map_d(double value, double smin, double smax, double emin, double emax);
double          lerp(double val1, double val2, double amount);
double          abs_d(double n);
unsigned int    ft_strlen(char *str);
void            ft_putstr(char *str);
int             request_input(char buffer[BUFFER_LEN]);
//void            ft_usleep(int ms);
void            *ft_memcpy(void *dst, const void *src, size_t n);

# define MAX(X, Y) ((X < Y) ? Y : X)
# define MIN(X, Y) ((X > Y) ? Y : X)



/*
**      MATH
*/
#define PI      3.14159265359f
#define LOG2    0.693147180559945309417232121458176568075f

double  log_d(double d);
int     msb(unsigned int x);
float   ft_sin(int n);
float   ft_cos(int n);

#endif  