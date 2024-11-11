#include"../inc/libmx.h"

char *mx_del_extra_spaces(const char *str)
{
    if(!str) return NULL;

     int b = 0;
     int h = mx_strlen(str);
    for(int i = 0; str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\n' || str[i] == '\f'; i++)
    {
        b++;
    }
    int e = h - 1;
     for(int i = h - 1; str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\n' || str[i] == '\f'; i--)
    {
        e--;
    }
    int t = 1;
    int l = 0;
    for(int i = b; i <= e; i++)
    {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\v' && str[i] != '\n' && str[i] != '\f')
        {
            t = 1;
        }
        if(str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\n' || str[i] == '\f')
        {
            l++;
        }
        else if(str[i] == ' ')
        {
            if(t == 1)
            {
                t = 0;
            }
            else
            {
                l++;
            }
        }
    }
    char *a = mx_strnew(e - b + 1 - l);
    int j = 0;
    for(int i = b; i <= e; i++)
    {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\v' && str[i] != '\n' && str[i] != '\f')
        {
            t = 1;
            a[j] = str[i];
            j++;
        }
        else if(str[i] == ' ')
        {
            if(t == 1)
            {
                a[j] = str[i];
                j++;
                t = 0;
            }
        }
    }
    return a;
}

