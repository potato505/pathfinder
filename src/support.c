#include"../inc/header.h"

int get_int(char* number)
{
    int n = 0;
   for(int i = 0; number[i] != '\0'; i++)
   {
    n *= 10;
    n = n + number[i] - 48;
   }
   return n;
}


void swap_string(const char **s1, const char **s2)
{
    const char* t = *s1;
    *s1 = *s2;
    *s2 = t;
}

void print_border()
{
    write(1, "========================================\n", 41);
}

t_edge** create_path_null(int n)
{
    t_edge **A = (t_edge **)malloc(sizeof(t_edge) * n);
    for(int i = 0; i < n; i++)
    {
        A[i] = NULL;
    }
    return A;
}

t_edge* graph_copy(t_edge *a, t_edge *b, int count)
{
    for(int i = 0; i < count; i++)
    {
        a[i].start = mx_strnew(mx_strlen(b[i].start));
        a[i].end = mx_strnew(mx_strlen(b[i].end));
        a[i].start = mx_strcpy(a[i].start, b[i].start);
        a[i].end = mx_strcpy(a[i].end, b[i].end);
        a[i].data = b[i].data;       
    }
    return a;
}

int rovno(t_edge A, t_edge B)
{
    return (!mx_strcmp(A.start, B.end) && !mx_strcmp(A.end, B.start)) || (!mx_strcmp(A.start, B.start) && !mx_strcmp(A.end, B.end));
}

int found_edge(t_edge **A, int count, int j, int J, int *a, int N)
{
    for(int i = J; i < N; i++)
    {
        if(i != j)
        {
            if(count == a[i])
            {
                if(rovno(A[i][count], A[j][count])) ///сравнивать должны с предлагаюзим путем|, то есть нужен еще + параметр для него в фунцию
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

//нужен масив который отобразит, что в путь не доабвлются использоваемые элементы


int have_edge(t_edge *A, t_edge B, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(rovno(A[i], B))
        {
            return 1;
        }
    }
    return 0;
}

int dont_have_str(char ** A, int k)
{
    for(int i = 0; i < k; i++)
    {
        if(!mx_strcmp(A[k], A[i]))
        {
            return 0;
        }
    }
    return 1;
}

char* need_extraspace(char* a)
{
    int i = 0;
    while(a[i] != '\0')
    {
        i++;
    }
    if(a[i - 1] != '\n')
    {
        a = mx_strjoin(a, "\n");
    }
    return a;
}

void print_str_error(char* str)
{
    write(2, str, mx_strlen(str));
}

