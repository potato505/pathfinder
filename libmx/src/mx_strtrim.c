#include"../inc/libmx.h"


char* mx_strtrim(const char* str)
{
    if(str == NULL)
    {
        return NULL;
    }
    int l = 0;
    int h = mx_strlen(str);
    for(int i = 0; str[i] != '\0' && (str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\n' || str[i] == '\f'); i++)
    {
        l++;
    }
    int s = 0;
    for(int i = 0; str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\n' || str[i] == '\f'; i++)
    {
        if(str[i] == ' ')
        {
            l++;
        }
        s++;
    }
    int e = h - 1;
     for(int i = h - 1; str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\n' || str[i] == '\f'; i--)
    {
        if(str[i] == ' ')
        {
            l++;
        }
        e--;
    }
    char* a = mx_strnew(h - l);
    int j = 0;
    while(s <= e)
    {
        if(str[s] == '\t' || str[s] == '\r' || str[s] == '\v' || str[s] == '\n' || str[s] == '\f')
        {
            s++;
        }
        else {
            a[j] = str[s];
            s++;
            j++;
        }
    }
    return a;
}



