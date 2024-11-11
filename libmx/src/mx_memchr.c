#include"../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n)
{
    unsigned char* a = (unsigned char*)s;
    for(size_t i = 0; i < n; i++)
    {
        if(a[i] == c)
        {
            return a + i;
        }
    }
    return NULL;
}

