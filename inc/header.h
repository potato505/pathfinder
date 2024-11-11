#ifndef HEADER_H
#define HEADER_H

#include "../libmx/inc/libmx.h"

typedef struct s_edge {

    char *start;
    char *end;

    int data;
    int use;
 

} t_edge;

int get_int(char* number);
t_edge* create_edges(char **a);
void swap_string(const char **s1, const char **s2);
void print_border();
t_edge** create_path_null(int n);
t_edge **create_graph(t_edge *edge, int n, int *N, int **a );
int rovno(t_edge A, t_edge B);
int found_edge(t_edge **A, int count, int j, int J, int *a, int N);
t_edge* graph_copy(t_edge *a, t_edge *b, int count);
int have_edge(t_edge *A, t_edge B, int n);
int print_path(t_edge path, t_edge * A, int a);
char* char_path(t_edge path, t_edge * A, int a);
int size_path(t_edge path, t_edge * A, int a);
char **strcores(t_edge *A, int n);
int dont_have_str(char ** A, int k);
void print_paths(t_edge ** A, int N, int *a, char **list);
char* need_extraspace(char* a);
void print_str_error(char* str);
int file_error(int argc, char *argv[]);

#endif

