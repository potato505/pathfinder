#include "../inc/libmx.h"

char *mx_file_to_str(const char *filename) 
{
    if (filename == NULL) 
    {
        return NULL;
    }
    int file = open(filename, O_RDONLY);
    if (file < 0)
    {
        return NULL;
    }
    int n = 0;
    char k;
    while (read(file, &k, 1))
    {
        n++;
    }
    close(file);
    file = open(filename, O_RDONLY);
    char *a = mx_strnew(n);
    int i = 0;
    while(read(file, &k, 1))
    {
        a[i] = k;
        i++;
    }
    close(file);
    return a;
}

