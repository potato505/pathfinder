#include "../inc/header.h"

int main(int argc, char *argv[])
{
    if(file_error(argc, argv))
    {
        return 0;
    }
    char* file = mx_file_to_str(argv[1]);
    char **path = mx_strsplit(file, '\n');
    if(error(path))
    {
        mx_strdel(path);
        free(file);
        return 0;
    }
    t_edge* edge = create_edges(path);
    int n = -1;
    for(int i = 0; path[i] != NULL; i++)
    {
        n++;
    }
    char **list = strcores(edge, n);
    if(error_info(edge, list, n, path[0]))
    {
        mx_strdel(path);
        free(file);
        for(int i = 0; i < n; i++)
        {
            free(edge[i].start);
            free(edge[i].end);
        }
        free(edge);
        mx_strdel(list);
        return 0;
    }
    int N;
    int *a = NULL;
    t_edge** graphs = create_graph(edge, n, &N, &a);
    print_paths(graphs, N, a,list);
    for(int i = 0; i < n; i++)
    {
        free(edge[i].start);
        free(edge[i].end);
    }
    free(edge);
    for (int i = 0; i < N && a[i] != -1; i++) 
    {
        for(int j=0; j <= a[i]; j++)
        {
            free(graphs[i][j].start);
            free(graphs[i][j].end);
        }
        free(graphs[i]);
    }
    free(a);
    free(graphs);
    free(file);
    mx_strdel(path);
    mx_strdel(list);
    return 0;
}

