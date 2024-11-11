
#include"../inc/libmx.h"

char* mx_strcat(char* s1, const char* s2)
{
    if(!s1  || !s2) return NULL;
    int i = mx_strlen(s1);
    int n = mx_strlen(s2);
    int j = 0;
    while(j <= n)
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    return s1;
}

