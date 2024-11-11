#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr)
{
    // if (nbr < 1)
    // {
    //     return 0;
    // }
    int n = 0;
    unsigned long i = 16;
    int k;
    while(i <= nbr)
    {
        n++;
        i = i * 16;
    }
    i = i / 16;
    char *a = mx_strnew(n);
    n = 0;
    while( i != 0)
    {
        k = nbr / i;
        if(k < 10)
        {
            a[n] = k + 48;
        }
        else if(k >= 10)
        {
            a[n] = k + 87;
        }
        nbr = nbr % i;
        i = i / 16;
        n++;
    }
    return a;
}



