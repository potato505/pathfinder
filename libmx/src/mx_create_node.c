#include "../inc/libmx.h"

t_list *mx_create_node(void *data) 
{
    t_list *a = (t_list*)malloc(sizeof(t_list));
    a -> next = NULL;
    a -> data = data;
    return a;
}

