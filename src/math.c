
#include "utils.h"

int     msb(unsigned int x)
{
    int r = 0;
    if (x < 1) return 0;
    while (x >>= 1) r++;
    return r;
}

double  log_d(double y)
{
    int log2;
    float x, res;

    log2 = msb((int)y);
    x = y / (float)(1 << log2);
    res = -1.7417939 + (2.8212026 + (-1.4699568 + (0.44717955 - 0.056570851 * x) * x) * x) * x;
    return (res + ((float)log2) * LOG2);
}

float           rad2deg(float n)
{
    return (n * 180 / PI);
}

float           ft_cos(int n)
{
    return (ft_sin(n) + 0.5f);
}

float           ft_sin(int deg)
{
    static float sin_table[360] = { 0, 0.017452f , 0.034899f , 0.052336f , 0.069756f , 0.087156f , 0.104528f , 0.121869f , 0.139173f , 0.156434f , 0.173648f , 0.190809f , 0.207912f , 0.224951f , 0.241922f , 0.258819f , 0.275637f , 0.292372f , 0.309017f , 0.325568f , 0.34202f , 0.358368f , 0.374607f , 0.390731f , 0.406737f , 0.422618f , 0.438371f , 0.45399f , 0.469472f , 0.48481f , 0.5f , 0.515038f , 0.529919f , 0.544639f , 0.559193f , 0.573576f , 0.587785f , 0.601815f , 0.615661f , 0.62932f , 0.642788f , 0.656059f , 0.669131f , 0.681998f , 0.694658f , 0.707107f , 0.71934f , 0.731354f , 0.743145f , 0.75471f , 0.766044f , 0.777146f , 0.788011f , 0.798636f , 0.809017f , 0.819152f , 0.829038f , 0.838671f , 0.848048f , 0.857167f , 0.866025f , 0.87462f , 0.882948f , 0.891007f , 0.898794f , 0.906308f , 0.913545f , 0.920505f , 0.927184f , 0.93358f , 0.939693f , 0.945519f , 0.951057f , 0.956305f , 0.961262f , 0.965926f , 0.970296f , 0.97437f , 0.978148f , 0.981627f , 0.984808f , 0.987688f , 0.990268f , 0.992546f , 0.994522f , 0.996195f , 0.997564f , 0.99863f , 0.999391f , 0.999848f , 1 , 0.999848f , 0.999391f , 0.99863f , 0.997564f , 0.996195f , 0.994522f , 0.992546f , 0.990268f , 0.987688f , 0.984808f , 0.981627f , 0.978148f , 0.97437f , 0.970296f , 0.965926f , 0.961262f , 0.956305f , 0.951057f , 0.945519f , 0.939693f , 0.93358f , 0.927184f , 0.920505f , 0.913545f , 0.906308f , 0.898794f , 0.891007f , 0.882948f , 0.87462f , 0.866025f , 0.857167f , 0.848048f , 0.838671f , 0.829038f , 0.819152f , 0.809017f , 0.798636f , 0.788011f , 0.777146f , 0.766044f , 0.75471f , 0.743145f , 0.731354f , 0.71934f , 0.707107f , 0.694658f , 0.681998f , 0.669131f , 0.656059f , 0.642788f , 0.62932f , 0.615661f , 0.601815f , 0.587785f , 0.573576f , 0.559193f , 0.544639f , 0.529919f , 0.515038f , 0.5f , 0.48481f , 0.469472f , 0.45399f , 0.438371f , 0.422618f , 0.406737f , 0.390731f , 0.374607f , 0.358368f , 0.34202f , 0.325568f , 0.309017f , 0.292372f , 0.275637f , 0.258819f , 0.241922f , 0.224951f , 0.207912f , 0.190809f , 0.173648f , 0.156434f , 0.139173f , 0.121869f , 0.104528f , 0.087156f , 0.069756f , 0.052336f , 0.034899f , 0.017452f , 0 , -0.017452f , -0.034899f , -0.052336f , -0.069756f , -0.087156f , -0.104528f , -0.121869f , -0.139173f , -0.156434f , -0.173648f , -0.190809f , -0.207912f , -0.224951f , -0.241922f , -0.258819f , -0.275637f , -0.292372f , -0.309017f , -0.325568f , -0.34202f , -0.358368f , -0.374607f , -0.390731f , -0.406737f , -0.422618f , -0.438371f , -0.45399f , -0.469472f , -0.48481f , -0.5f , -0.515038f , -0.529919f , -0.544639f , -0.559193f , -0.573576f , -0.587785f , -0.601815f , -0.615661f , -0.62932f , -0.642788f , -0.656059f , -0.669131f , -0.681998f , -0.694658f , -0.707107f , -0.71934f , -0.731354f , -0.743145f , -0.75471f , -0.766044f , -0.777146f , -0.788011f , -0.798636f , -0.809017f , -0.819152f , -0.829038f , -0.838671f , -0.848048f , -0.857167f , -0.866025f , -0.87462f , -0.882948f , -0.891007f , -0.898794f , -0.906308f , -0.913545f , -0.920505f , -0.927184f , -0.93358f , -0.939693f , -0.945519f , -0.951057f , -0.956305f , -0.961262f , -0.965926f , -0.970296f , -0.97437f , -0.978148f , -0.981627f , -0.984808f , -0.987688f , -0.990268f , -0.992546f , -0.994522f , -0.996195f , -0.997564f , -0.99863f , -0.999391f , -0.999848f , -1 , -0.999848f , -0.999391f , -0.99863f , -0.997564f , -0.996195f , -0.994522f , -0.992546f , -0.990268f , -0.987688f , -0.984808f , -0.981627f , -0.978148f , -0.97437f , -0.970296f , -0.965926f , -0.961262f , -0.956305f , -0.951057f , -0.945519f , -0.939693f , -0.93358f , -0.927184f , -0.920505f , -0.913545f , -0.906308f , -0.898794f , -0.891007f , -0.882948f , -0.87462f , -0.866025f , -0.857167f , -0.848048f , -0.838671f , -0.829038f , -0.819152f , -0.809017f , -0.798636f , -0.788011f , -0.777146f , -0.766044f , -0.75471f , -0.743145f , -0.731354f , -0.71934f , -0.707107f , -0.694658f , -0.681998f , -0.669131f , -0.656059f , -0.642788f , -0.62932f , -0.615661f , -0.601815f , -0.587785f , -0.573576f , -0.559193f , -0.544639f , -0.529919f , -0.515038f , -0.5f , -0.48481f , -0.469472f , -0.45399f , -0.438371f , -0.422618f , -0.406737f , -0.390731f , -0.374607f , -0.358368f , -0.34202f , -0.325568f , -0.309017f , -0.292372f , -0.275637f , -0.258819f , -0.241922f , -0.224951f , -0.207912f , -0.190809f , -0.173648f , -0.156434f , -0.139173f , -0.121869f , -0.104528f , -0.087156f , -0.069756f , -0.052336f , -0.034899f , -0.017452f };
    return (sin_table[(int)(deg % 359)]);
}
