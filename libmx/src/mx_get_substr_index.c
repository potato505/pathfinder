#include"../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub)
{
    if(!str || !sub)
    {
        return -2;
    }
    int n = mx_strlen(sub);
    for(int i = 0; str[i] != '\0'; i++ )
    {
        if(str[i] == sub[0])
        {
            for(int j = 0; j < n; j++)
            {
                if(sub[j] != str[i + j])
                {
                    break;
                }
                if(j == n - 1)
                {
                    return i;
                }
            }
        }
    }
    return -1;
}

