#include"../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char* hex)
{
    if(hex == NULL)
    {
        return 0;
    }
    unsigned long k = 0;

    for(int i = 0; hex[i] != '\0'; i++)
    {
        k *= 16;
        if(hex[i] >= 48 && hex[i] <= 57)
        {
            k = k + (hex[i] - 48);
        }
        else if((hex[i] >= 65 && hex[i] <= 90) || (hex[i] >= 97 && hex[i] <= 122))
        {
            if(hex[i] >= 97 && hex[i] <= 122)
            {
                k = k + (hex[i] - 87);
            }
            else
            {
                k = k + (hex[i] - 55);
            }
        }
    }
    return k;
}

