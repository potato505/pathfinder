#include "../inc/libmx.h"

char *mx_itoa(int number)
{
    int t = 1;
    int m = 0;
    if(number < 0)
    {
        number*=-1;
        m = 1;
    }
    int i = 1, k;
    while( number / i >= 10)
    {
        i = i * 10;
        t++;
    }
    char* a = mx_strnew(m + t);
    if(m == 1)
    {
        a[0] = '-';
    }
    while(i != 0)
    {
        k = number / i;
        k = k % 10 + 48;
        i = i / 10;
        a[m] = k;
        m++;
    }
    return a; 
}

