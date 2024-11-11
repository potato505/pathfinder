#include"../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n)
{
    unsigned char* a = (unsigned char*)s;
    for(size_t i = n - 1; i >= 0; i--)
    {
        if(a[i] == c)
        {
            return a + i;
        }
    }
    return NULL;
}
