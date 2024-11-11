#include "../inc/header.h"

int main(int argc, char *argv[])
{
    if(file_error(argc, argv))
    {
        return 0;
    }
    char* file = mx_file_to_str(argv[1]);
    char **path = mx_strsplit(file, '\n');
    t_edge* edge = create_edges(path);
    int n = -1;
    for(int i = 0; path[i] != NULL; i++)
    {
        n++;
        printf("%s\n", path[i]);
    }
    printf("%i\n", n);
    print_border();
    for(int i = 0; i < n; i++)
    {
        mx_printstr(edge[i].start);
        mx_printchar('-');
        mx_printstr(edge[i].end);
        mx_printchar(',');
        mx_printint(edge[i].data);
        mx_printchar('\n');
    }
    int N;
    int *a = NULL;
    t_edge** graphs = create_graph(edge, n, &N, &a);
    printf("zakonchen\n");
    for(int i = 0; i < n * n && a[i] != -1; i++)
    {
        printf("%i\n", a[i]);
    }
    printf("N=%i\n", N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= a[i]; j++)
        {
            mx_printstr(graphs[i][j].start);
            mx_printchar('-');
            mx_printstr(graphs[i][j].end);
            mx_printchar(',');
            mx_printint(graphs[i][j].data);
            mx_printchar('\n');
        }
        printf("=======================\n");       
    }
    t_edge p;
    p.start = mx_strnew(mx_strlen("Fraser"));
    p.start = mx_strcpy(p.start, "Fraser");
    p.end = mx_strnew(mx_strlen("Java"));
    p.end = mx_strcpy(p.end, "Java");
    char **list = strcores(edge, n);
    for(int i = 0; list[i] != NULL; i++)
    {
        printf("%s\n", list[i]);
    }
    print_border();
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

