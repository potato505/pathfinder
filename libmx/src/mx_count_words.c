#include "../inc/libmx.h"

int mx_count_words(const char *str, char c)
{
    if(!str)    return -1;
    int count = 0;
    int t = 1;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != c && t == 1)
        {
            count++;
            t = 0;
        }
        if(str[i] == c)
        {
            t = 1;
        }

    }
    return count;
}

