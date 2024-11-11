#include "../inc/libmx.h"

int mx_strcmp(const char*s1, const char*s2)
{
    if(!s1 || !s2)
    {
        return -1;
    }
    int i = 0;
    int j = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    i = 0;
    while(s1[i] != '\0')
    {
        i++;
    }
    while(s2[j] != '\0')
    {
        j++;
    }
    return i - j;
}

