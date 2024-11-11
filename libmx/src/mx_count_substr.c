#include"../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub)
{
    if(!str || !sub)
    {
        return -1;
    }
    int n = mx_strlen(sub);
    int k = 0;
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
                    k++;
                }
            }
        }
    }
    return k;
}

