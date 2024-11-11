#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right)
{
    if(arr == NULL)
    {
        return -1;
    }
    int swaps = 0;
    int  i = left;
    int j = right;
    if(i < j)
    {
        int pivot = mx_strlen(arr[(i + j) / 2]);
        while(i <= j )
        {
            while(mx_strlen(arr[i]) < pivot)
            {
                i++;
            }
             while(mx_strlen(arr[j]) > pivot)
            {
                j--;
            }
            if(i <= j)
            {
                if(mx_strlen(arr[i]) != mx_strlen(arr[j]))
                {
                    char *temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    swaps++;
                }
                i++;
                j--;
            }
        }
        swaps += mx_quicksort(arr, left, j);
        swaps += mx_quicksort(arr, i, right); 
    }
    return swaps;
}

