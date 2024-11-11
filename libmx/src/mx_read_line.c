#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd)
{
      if (fd < 0) 
      {
        return -2;
      }

    *lineptr = mx_strnew(buf_size);
    size_t i = 0;
    char *k = mx_strnew(buf_size);
    size_t size;
    int d;

    while ((size = read(fd, k, buf_size)) > 0) 
    {
        d = mx_get_char_index(k, delim);

        if (d == -1) 
        {
            *lineptr = mx_realloc(*lineptr, i + size + 1);
            mx_memcpy(*lineptr + i, k, size);
            i += size;
        } else 
        {
            *lineptr = mx_realloc(*lineptr, i + d + 1);
            mx_memcpy(*lineptr + i, k, d);
            (*lineptr)[i + d] = '\0';
            free(k);
            return i + d;
        }
    }
    if(size == 0 && i == 0)
    {
        return -1;
    }
    (*lineptr)[i] = '\0';
    free(k);
    return i;
}

