#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    void *p = NULL;
    if(!ptr) 
    {
        ptr = malloc(size);
    }
    else if(ptr)
    {
        p = malloc(size);
        if(!p)
        {
            return ptr;
        }
        mx_memcpy(p, ptr, size);
        ptr = malloc(size);
        mx_memcpy(ptr, p, size);
    }
    free(p);
    return ptr;
}

