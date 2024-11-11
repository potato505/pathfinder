#include "../inc/libmx.h"

void mx_printint(int n)
{
    if(n < 0)
    {
         write(1, "-", 1);
        n*=-1;
    }
    int i = 1, k;
    while( n / i >= 10)
    {
        i = i * 10;
    }
    while(i != 0)
    {
        k = n / i;
        k = k % 10 + 48;
        i = i / 10;
        write(1, &k, 1);
    }    
}

