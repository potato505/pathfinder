#include"../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
    if(!str || !sub || !replace)
    {
        return NULL;
    }
    int t;
    int n = mx_strlen(str);
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == sub[0])
        {
            t = 1;
            for(int j = 0; sub[j] != '\0'; j++)
            {
                if(str[i + j] != sub[j])
                {
                    t = 0;
                    break;
                }
            }
            if(t)
            {
                n = n - mx_strlen(sub) + mx_strlen(replace);
            }
        }
        i++;
    }
    char* a = mx_strnew(n);
    i = 0;
    int k = 0;
    while( i < n)
    {
        if(str[k] == sub[0])
        {
            t = 1;
            for(int j = 0; sub[j] != '\0'; j++)
            {
                if(str[k + j] != sub[j])
                {
                    t = 0;
                    continue;;
                }
            }
            if(t)
            {
                for(int I = 0; replace[I] != '\0'; I++)
                {
                    a[i] = replace[I];
                    i++;
                }
                k += mx_strlen(sub);
                continue;
            }
        }
        a[i] = str[k];
        k++;
        i++;
    }
    return a;
}

