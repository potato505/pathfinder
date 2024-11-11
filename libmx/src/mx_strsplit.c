#include"../inc/libmx.h"

char **mx_strsplit(const char *s, char c)
{
        if (!s) 
        {
        return NULL;
    }

    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) 
    {
        if (s[i] != c && (i == 0 || s[i - 1] == c)) 
        {
            count++;
        }
    }

    char **a = (char**)malloc((count + 1) * sizeof(char*));
    if (a == NULL) 
    {
        return NULL;
    }
    a[count] = NULL;

    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) 
    {
        if (s[i] != c && (i == 0 || s[i - 1] == c)) 
        {
            int start = i;
            int end = i;
            while (s[end] != '\0' && s[end] != c) 
            {
                end++;
            }
            a[j] = mx_strndup(s + start, end - start);
            if (a[j] == NULL) {
                for (int k = 0; k < j; k++) 
                {
                    free(a[k]);
                }
                free(a);
                return NULL;
            }
            j++;
        }
    }

    return a;
}

