#include"../inc/libmx.h"

int mx_list_size(t_list *list)
{
    if (list == NULL)
    {
        return 0;
    }
    t_list *temp = list;
    int i = 1;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
        i++;
    }
    return i;
}

