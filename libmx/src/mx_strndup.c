#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    if(!s1) return NULL;
    if(n > (size_t)mx_strlen(s1))
    {
        n = mx_strlen(s1);
    }

    char *a = (char*)malloc(n * sizeof(char));

    for(size_t i = 0; i < n; i++)
    {
        a[i] = s1[i];
    }
    
    a[n] = '\0';
    return a;
}

