#include "../inc/libmx.h"


int mx_bubble_sort(char** arr, int size)
{
    if(!arr)
    {
        return -1;
    }
    char* a;
    int swap = 0;
    for(int i = 0; i < size -1; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(mx_strcmp(arr[j], arr[j+1]) > 0)
            {
                a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
                swap++;
            }
        }
    }
    return swap;
}



