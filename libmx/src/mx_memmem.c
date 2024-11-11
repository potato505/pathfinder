#include "../inc/libmx.h"

void *mx_memmem( void *big, size_t big_len, void *little, size_t little_len)
{
     if(!big || !little)
    {
        return NULL;
    }
    unsigned char* b = (unsigned char*)big;
    unsigned char* l = (unsigned char*)little;
    for(size_t i = 0; i < big_len; i++)
    {
        if(b[i] == l[0])
        {
            for(size_t j = 0; j < little_len; j++)
            {
                if(l[j] != b[i + j])
                {
                    break;
                }
                if(j == little_len - 1)
                {
                    return b + i;
                }
            }
        }
    }
    return NULL;
}

