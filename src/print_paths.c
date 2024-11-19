#include"../inc/header.h"

char* char_path(t_edge path, t_edge * A, int a)
{

    int start = -1;
    int end = -1;
    int data = 0;
    for(int j = 0; j <= a; j++)
    {            
        if((!mx_strcmp(path.start, A[j].start) || !mx_strcmp(path.start, A[j].end)) && start == -1)
        {
            start = j;            
        }
        if((!mx_strcmp(path.end, A[j].start) || !mx_strcmp(path.end, A[j].end)) && end == -1)          
        {
            end = j;
        }
    }
    char *P = "";
    if(end != -1 && start != -1)
    {
        if(start < end)
        {
            if(!mx_strcmp(path.start, A[start].end))
            {
                start++;
            }
            P = mx_strjoin(P,"Path: ");
            P = mx_strjoin(P,A[start].start);
            P = mx_strjoin(P," -> ");
            P = mx_strjoin(P,A[end].end);
            P = mx_strjoin(P,"\n");
            P = mx_strjoin(P,"Route: ");
            P = mx_strjoin(P, A[start].start);
            for(int i = start; i <= end; i++)
            {
                P = mx_strjoin(P," -> ");
                P = mx_strjoin(P,A[i].end);
            }
            P = mx_strjoin(P,"\n");
            P = mx_strjoin(P,"Distance: ");
            P = mx_strjoin(P,mx_itoa(A[start].data));
            data = A[start].data;
            if(end - start > 0)
            {
                for(int i = start + 1; i <= end; i++)
                {
                    P = mx_strjoin(P," + ");
                    P = mx_strjoin(P,mx_itoa(A[i].data));
                    data+= A[i].data;
                }
                P = mx_strjoin(P," = ");
                P = mx_strjoin(P,mx_itoa(data));
                P = mx_strjoin(P,"\n");
            }
            
        }
        else if(start > end)
        {
            if(!mx_strcmp(A[end].end, path.end))
            {
                end++;
            }
            P = mx_strjoin(P,"Path: ");
            P = mx_strjoin(P,A[start].end);
            P = mx_strjoin(P," -> ");
            P = mx_strjoin(P,A[end].start);
            P = mx_strjoin(P,"\n");
            P = mx_strjoin(P,"Route: ");
            P = mx_strjoin(P,A[start].end);
            for(int i = start; i >= end; i--)
            {
                P = mx_strjoin(P," -> ");
                P = mx_strjoin(P,A[i].start);
            }
            P = mx_strjoin(P,"\n");
            P = mx_strjoin(P,"Distance: ");
            P = mx_strjoin(P,mx_itoa(A[start].data));
            data = A[start].data;
            if(start - end > 0)
            {
                for(int i = start - 1; i >= end; i--)
                {
                    P = mx_strjoin(P," + ");
                    P = mx_strjoin(P,mx_itoa(A[i].data));
                    data+= A[i].data;
                }
                P = mx_strjoin(P," = ");
                P = mx_strjoin(P, mx_itoa(data));
                P = mx_strjoin(P,"\n");
            }

            
        }
        else 
        {
            P = mx_strjoin(P,"Path: ");
            P = mx_strjoin(P,path.start);
            P = mx_strjoin(P," -> ");
            P = mx_strjoin(P,path.end);
            P = mx_strjoin(P,"\n");
            P = mx_strjoin(P,"Route: ");
            P = mx_strjoin(P,path.start);
            P = mx_strjoin(P," -> ");
            P = mx_strjoin(P,path.end);
            P = mx_strjoin(P,"\n");
            P = mx_strjoin(P, "Distance: ");
            P = mx_strjoin(P, mx_itoa(A[start].data));
            P = mx_strjoin(P,"\n");
        }
    }
    return P;
}

char* shortchar_path(t_edge path, t_edge * A, int a)
{

    int start = -1;
    int end = -1;
    for(int j = 0; j <= a; j++)
    {            
        if((!mx_strcmp(path.start, A[j].start) || !mx_strcmp(path.start, A[j].end)) && start == -1)
        {
            start = j;            
        }
        if((!mx_strcmp(path.end, A[j].start) || !mx_strcmp(path.end, A[j].end)) && end == -1)          
        {
            end = j;
        }
    }
    char *P = "";
    if(end != -1 && start != -1)
    {
        if(start < end)
        {
            if(!mx_strcmp(path.start, A[start].end))
            {
                start++;
            }
            P = mx_strjoin(P, A[start].start);
            for(int i = start; i <= end; i++)
            {
                P = mx_strjoin(P,"\n");
                P = mx_strjoin(P,A[i].end);
            }
            P = mx_strjoin(P,"\n");
            
        }
        else if(start > end)
        {
            if(!mx_strcmp(A[end].end, path.end))
            {
                end++;
            }
            P = mx_strjoin(P,A[start].end);
            for(int i = start; i >= end; i--)
            {
                P = mx_strjoin(P,"\n");
                P = mx_strjoin(P,A[i].start);
            }
            P = mx_strjoin(P,"\n");
        }
        else 
        {
            P = mx_strjoin(P,path.start);
            P = mx_strjoin(P,"\n");
            P = mx_strjoin(P,path.end);
            P = mx_strjoin(P,"\n");
        }
    }
    return P;
}


int size_path(t_edge path, t_edge * A, int a)
{

    int start = -1;
    int end = -1;
    int data = 0;
    for(int j = 0; j <= a; j++)
    {            
        if((!mx_strcmp(path.start, A[j].start) || !mx_strcmp(path.start, A[j].end)) && start == -1)
        {
            start = j;            
        }
        if((!mx_strcmp(path.end, A[j].start) || !mx_strcmp(path.end, A[j].end)) && end == -1)          
        {
            end = j;
        }
    }
    if(end != -1 && start != -1)
    {
        if(start < end)
        {
            if(!mx_strcmp(path.start, A[start].end))
            {
                start++;
            }
            data = A[start].data;
            if(end - start > 0)
            {
                for(int i = start + 1; i <= end; i++)
                {
                    data+= A[i].data;
                }
            }
            
        }
        else if(start > end)
        {
            if(!mx_strcmp(A[end].end, path.end))
            {
                end++;
            }
            data = A[start].data;
            if(start - end > 0)
            {
                for(int i = start - 1; i >= end; i--)
                {
                    data+= A[i].data;
                }
            }
            
        }
        else 
        {
            return A[start].data;
        }
        return data;
    }
    return -1;
}


int print_path(t_edge path, t_edge * A, int a)
{

    int start = -1;
    int end = -1;
    int data = 0;
    for(int j = 0; j <= a; j++)
    {            
        if((!mx_strcmp(path.start, A[j].start) || !mx_strcmp(path.start, A[j].end)) && start == -1)
        {
            start = j;            
        }
        if((!mx_strcmp(path.end, A[j].start) || !mx_strcmp(path.end, A[j].end)) && end == -1)          
        {
            end = j;
        }
    }
    if(end != -1 && start != -1)
    {
        print_border();
        if(start < end)
        {
            if(!mx_strcmp(path.start, A[start].end))
            {
                start++;
            }
            mx_printstr("Path: ");
            mx_printstr(A[start].start);
            mx_printstr(" -> ");
            mx_printstr(A[end].end);
            mx_printchar('\n');
            mx_printstr("Route: ");
            mx_printstr(A[start].start);
            for(int i = start; i <= end; i++)
            {
                mx_printstr(" -> ");
                mx_printstr(A[i].end);
            }
            mx_printchar('\n');
            mx_printstr("Distance: ");
            mx_printint(A[start].data);
            data = A[start].data;
            if(end - start > 0)
            {
                for(int i = start + 1; i <= end; i++)
                {
                    mx_printstr(" + ");
                    mx_printint(A[i].data);
                    data+= A[i].data;
                }
                mx_printstr(" = ");
                mx_printint(data);
                mx_printchar('\n');
            }
            
        }
        else if(start > end)
        {
            if(!mx_strcmp(A[end].end, path.end))
            {
                end++;
            }
            mx_printstr("Path: ");
            mx_printstr(A[start].end);
            mx_printstr(" -> ");
            mx_printstr(A[end].start);
            mx_printchar('\n');
            mx_printstr("Route: ");
            mx_printstr(A[start].end);
            for(int i = start; i >= end; i--)
            {
                mx_printstr(" -> ");
                mx_printstr(A[i].start);
            }
            mx_printchar('\n');
            mx_printstr("Distance: ");
            mx_printint(A[start].data);
            data = A[start].data;
            if(start - end > 0)
            {
                for(int i = start - 1; i >= end; i--)
                {
                    mx_printstr(" + ");
                    mx_printint(A[i].data);
                    data+= A[i].data;
                }
                mx_printstr(" = ");
                mx_printint(data);
                mx_printchar('\n');
            }

            
        }
        else 
        {
            mx_printstr("Path: ");
            mx_printstr(path.start);
            mx_printstr(" -> ");
            mx_printstr(path.end);
            mx_printchar('\n');
            mx_printstr("Route: ");
            mx_printstr(path.start);
            mx_printstr(" -> ");
            mx_printstr(path.end);
            mx_printchar('\n');
            mx_printstr("Distance: ");
            mx_printint(A[start].data);
            mx_printchar('\n');
        }
        print_border();
        return 1;
    }
    return 0;
}

char **strcores(t_edge *A, int n)
{
    int N = 0;
    int t[2];
    for(int i = 0; i < n; i++)
    {
        t[0] = 1;
        t[1] = 1;
        for(int j = 0; j < i; j++)
        {
            if(!mx_strcmp(A[i].start, A[j].start) || !mx_strcmp(A[i].start, A[j].end))
            {
                t[0] = 0;
            }
            if(!mx_strcmp(A[i].end, A[j].start) || !mx_strcmp(A[i].end, A[j].end))
            {
                t[1] = 0;
            }
        }
        N = N + t[0] + t[1];
    }
    char **str = (char**)malloc(sizeof(char*) * (N + 1));
    str[N] = NULL;
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        t[0] = 1;
        t[1] = 1;
        for(int j = 0; j < i; j++)
        {
            if((!mx_strcmp(A[i].start, A[j].start) || !mx_strcmp(A[i].start, A[j].end)))
            {
                t[0] = 0;
            }
            if(!mx_strcmp(A[i].end, A[j].start) || !mx_strcmp(A[i].end, A[j].end))
            {
                t[1] = 0;
            }
        }
        if(t[0])
        {
            str[k] = mx_strnew(mx_strlen(A[i].start));
            str[k] = mx_strcpy(str[k], A[i].start);
            k++;
        }
        if(t[1])
        {
            str[k] = mx_strnew(mx_strlen(A[i].end));
            str[k] = mx_strcpy(str[k], A[i].end);
            k++;
        }
    }
    return str;
}


void print_shortest(char **paths, int *dis, int great_data, int N, char **list, char **shortp) {
    
    int *a = (int *)malloc(N * sizeof(int));
    char ***A = (char ***)malloc(sizeof(char **) * N);
    for (int i = 0; i < N; i++) 
    {
        a[i] = -1;
        A[i] = mx_strsplit(shortp[i], '\n');
    }
    int na = 0;
    int nc = 0;

    for (int i = 0; i < N; i++) {
        if (dis[i] == great_data && dont_have_str(paths, i) && dis[i] != -1) {
            a[i] = 0;
            na++;
            int word_count = mx_count_words(shortp[i], '\n');
            if (word_count > nc) 
            {
                nc = word_count;
            }
        }
    }
    for(int i = 0; i < na; i++)
    {
        int step = 1;
        for(int count = 0; count != 1 && step < nc; step++)
        {
            count = 0;
            int first = 1;
            for(int j = 0; (list[j] != NULL && count == 0) || first; j++)
            {
                first = 0;
                for(int k = 0; k < N; k++)
                {
                    if(!mx_strcmp(A[k][step], list[j]) && a[k] == step - 1)
                    {
                        count++;
                        a[k] = step;
                    }
                }
            }
        }
        for(int j = 0; j < N; j++)
        {
            if(a[j] == step - 1)
            {
                print_border();
                mx_printstr(paths[j]);
                print_border();
                a[j] = -1;
                break;
            }
            else if(a[j] != -1)
            {
                a[j] = 0;
            }
        }

    }
      for (int i = 0; i < N; i++) 
      {
        if (A[i] != NULL) 
        {
            int k = 0;
            while (A[i][k] != NULL) 
            {
                free(A[i][k]);
                k++;
            }
            free(A[i]);
        }
    }
    free(A);
    free(a);
}



void print_paths(t_edge ** A, int N, int *a, char **list)
{
    char **paths = (char **)malloc(N* sizeof(char *));
    char **shortp = (char **)malloc(N* sizeof(char *));
    t_edge path;
    int *dis = (int*)malloc(sizeof(int) * N);
    for(int i = 0; list[i] != NULL; i++)
    {
        for(int j = i + 1; list[j] != NULL; j++)
        {
            path.start = list[i];
            path.end = list[j];
            for(int k = 0; k < N; k++)
            {
                dis[k] = size_path(path, A[k], a[k]);
                paths[k] = char_path(path, A[k], a[k]);
                paths[k] = need_extraspace(paths[k]);
                shortp[k] = shortchar_path(path, A[k], a[k]);
            }
            int great_data = dis[0];
            for(int k = 1; k < N; k++)
            {
                if((great_data > dis[k] && dis[k] != -1) || great_data == -1)
                {
                    great_data = dis[k];
                }
            }
            print_shortest(paths, dis, great_data, N, list, shortp);
            // for(int k = 0; k < N; k++)
            // {
            //     if(dis[k] == great_data && dont_have_str(paths, k) && dis[k] != -1)
            //     {
            //         print_border();
            //         mx_printstr(paths[k]);
            //         print_border();
            //     }
            // }
        }
    }

    free(dis);
}

