#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim)
{
    if(arr != NULL && delim != NULL && arr[0] != NULL)
    {
        int i = 0;
        while(arr[i+1])
        {
            mx_printstr(arr[i]);
            mx_printstr(delim);
            i++;
        }
        mx_printstr(arr[i]);
        mx_printchar('\n');
    }
}

