#include "../inc/libmx.h"

char* mx_strnew(const int size)
{
    char* a = (char*)malloc(sizeof(char) * (size + 1));
    for(int i = 0; i <= size; i++)
    {
        a[i] = '\0';
    }
    return a;
}

