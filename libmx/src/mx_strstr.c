#include"../inc/libmx.h"


char* mx_strstr(const char* s1, const char* s2)
{
    if(!s1 || !s2)
    {
        return NULL;
    }
    int n = mx_strlen(s2);
    for(const char* i = s1; *i != '\0'; i++)
    {
        if(*i == s2[0])
        {
            for(int j = 0; j < n; j++)
            {
                if(s2[j] != *(i + j))
                {
                    break;
                }
                if(j == n - 1)
                {
                    return (char*)i;
                }
            }
        }
    }
    return NULL;
}


