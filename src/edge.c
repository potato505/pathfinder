#include"../inc/header.h"


t_edge* create_edges(char **a)
{
    int count = -1;
    while(a[count] != NULL)
    {
        count++;
    }
    t_edge* A = (t_edge*)malloc(sizeof(t_edge) * count);
    for(int i = 0; a[i + 1] != NULL; i++)
    {
        A[i].use = 1;
        int j = 0;
        while(a[i + 1][j] != '-')
        {
            j++;
        }
        A[i].start = mx_strnew(j);
        A[i].start = mx_strncpy(A[i].start, a[i + 1], j);
        j++;
        int k = 0;
        while(a[i + 1][j + k] != ',')
        {
            k++;
        }
        A[i].end = mx_strnew(k );
        A[i].end = mx_strncpy(A[i].end, a[i + 1] + j, k);
        A[i].data = get_int(a[i + 1] + j + k + 1);
    }
    return A;
}

t_edge **create_graph(t_edge *edge, int n, int *N, int **a )
{
    *N = 0;
    *a = (int*)malloc(sizeof(int) * (n * n * 2));
    for(int i = 0; i < (n * n); i++)
    {
        (*a)[i] = -1;
    }
    t_edge **paths = (t_edge **)malloc(sizeof(t_edge *) * (n * n * 2));
    for(int i = 0 ; i < (n * n * 2); i++)
    {
        paths[i] = (t_edge *)malloc(sizeof(t_edge) * (n));
    }
    for(int i = 0; i < n; i++)
    {
        int count = 1;
        if(edge[i].use)
        {
            edge[i].use = 0;
            paths[*N][0].start = mx_strnew(mx_strlen(edge[i].start));
            paths[*N][0].end = mx_strnew(mx_strlen(edge[i].end));
            paths[*N][0].start = mx_strcpy(paths[*N][0].start, edge[i].start);
            paths[*N][0].end = mx_strcpy(paths[*N][0].end, edge[i].end);
            paths[*N][0].data = edge[i].data;
            (*a)[*N] = 0;
            *N= *N + 1;
        }
        else {
        continue;
        }
        int J = *N -1;
       for(int new = 1; new; count++)
       {
        new = 0;
        for(int j = J; j < *N; j++)
        {
            while((*a)[j] != count - 1)
            {
                if(j + 1 == *N)
                {
                    break;
                }
                j++;
                }
            if(j + 1 == *N && (*a)[j] != count - 1)
            {
                break;
            }
            for(int t = 0; t < n; t++)
            {
                if(!mx_strcmp(paths[j][count - 1].end, edge[t].start) && (*a)[j] == count - 1 && !have_edge(paths[j], edge[t], count) && !have_island(paths[j], edge[t], count))
                {
                    new = 1;
                    (*a)[j] = count;
                    paths[j][count].start = mx_strnew(mx_strlen(edge[t].start));
                    paths[j][count].end = mx_strnew(mx_strlen(edge[t].end));
                    paths[j][count].start = mx_strcpy(paths[j][count].start, edge[t].start);
                    paths[j][count].end = mx_strcpy(paths[j][count].end, edge[t].end);
                    paths[j][count].data = edge[t].data;
                }
                else if(!mx_strcmp(paths[j][count - 1].end, edge[t].end) && (*a)[j] == count - 1 && !have_edge(paths[j], edge[t], count) && !have_island(paths[j], edge[t], count))
                {
                    new = 1;
                    (*a)[j] = count;
                    paths[j][count].start = mx_strnew(mx_strlen(edge[t].end));
                    paths[j][count].end = mx_strnew(mx_strlen(edge[t].start));
                    paths[j][count].start = mx_strcpy(paths[j][count].start, edge[t].end);
                    paths[j][count].end = mx_strcpy(paths[j][count].end, edge[t].start);
                    paths[j][count].data = edge[t].data;
                }
                else if(!mx_strcmp(paths[j][count - 1].end, edge[t].start) && (*a)[j] == count && !have_edge(paths[j], edge[t], count) && *N < (n * n) && !have_island(paths[j], edge[t], count))
                {
                    new = 1;
                    (*a)[*N] = count;
                    paths[*N] = graph_copy(paths[*N], paths[j], count);
                    paths[*N][count].start = mx_strnew(mx_strlen(edge[t].start));
                    paths[*N][count].end = mx_strnew(mx_strlen(edge[t].end));
                    paths[*N][count].start = mx_strcpy(paths[*N][count].start, edge[t].start);
                    paths[*N][count].end = mx_strcpy(paths[*N][count].end, edge[t].end);
                    paths[*N][count].data = edge[t].data;
                    *N= *N + 1;
                }
                else if(!mx_strcmp(paths[j][count - 1].end, edge[t].end) && (*a)[j] == count && !have_edge(paths[j], edge[t], count) && *N < (n * n) && !have_island(paths[j], edge[t], count))
                {
                    new = 1;
                    (*a)[*N] = count;
                    paths[*N] = graph_copy(paths[*N], paths[j], count);
                    paths[*N][count].start = mx_strnew(mx_strlen(edge[t].end));
                    paths[*N][count].end = mx_strnew(mx_strlen(edge[t].start));
                    paths[*N][count].start = mx_strcpy(paths[*N][count].start, edge[t].end);
                    paths[*N][count].end = mx_strcpy(paths[*N][count].end, edge[t].start);
                    paths[*N][count].data = edge[t].data;
                    *N= *N + 1;
                }    
        }
            }

       }

    }
    return paths;
}

