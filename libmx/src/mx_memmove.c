#include"../inc/libmx.h"

void *mx_memmove(void *dst, void *src, size_t len)
{
    unsigned char* d = (unsigned char*)dst;
    unsigned char* s = (unsigned char*)src;
    if((s <= d && s + len >= d) || (d <= s && d + len >= s))
    {
        unsigned char *k = (unsigned char*)malloc(len);
        k = mx_memcpy(k, s, len);
        for(size_t i = 0; i < len; i++)
        {
            d[i] = k[i];
        }
        free(k);
    }
    else 
    {
        for(size_t i = 0; i < len; i++)
        {
            d[i] = s[i];
        }
    }
    return dst;
}

