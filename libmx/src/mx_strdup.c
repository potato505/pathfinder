#include"../inc/libmx.h"

char* mx_strdup(const char* str)
{
    if(str == NULL)
    {
        return NULL;
    }
    int n = 0;
    for(int i = 0; str[i] != 0; i++)
    {
        n++;
    }
    char *a = (char*)malloc(sizeof(char) * n + 1);
    for(int i = 0; i < n; i++)
    {
        a[i] = str[i];
    }
    a[n] = '\0';
    return a;
}

