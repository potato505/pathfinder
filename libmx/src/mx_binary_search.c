#include "../inc/libmx.h"

int mx_binary_search(char** arr, int size, const char* s, int* count)
{
    if(!arr || !s || !count)
    {
        return -1;
    }
    int h = size -1;
    int l = 0;
    int mid;
    while(l <= h)
    {
        mid = (l + h) / 2;
        (*count)++;
        if(mx_strcmp(arr[mid], s) == 0)
        {
            return mid;
        }

        if(mx_strcmp(arr[mid], s) < 0)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    *count = 0;
    return -1;
}

