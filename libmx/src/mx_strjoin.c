#include"../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2)
{
    if(!s1 && !s2)
    {
        return NULL;
    }
    else if(!s1)
    {
        return (char*)s2;
    }
    else if(!s2)
    {
        return (char*)s1;
    }
    else 
    {
        char* a = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        int j = 0;
        for(int i = 0; s1[i] != '\0'; i++)
        {
            a[j] = s1[i];
            j++; 
        }
        for(int i = 0; s2[i] != '\0'; i++)
        {
            a[j] = s2[i];
            j++; 
        }
        return a;
    }
}

