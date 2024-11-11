#include"../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *))
{
    if (!lst || !lst->next)
    {
        return lst;
    }
    int b = 1;
    t_list *temp;
    while (b) {
        b = 0;  
        temp = lst;

        while (temp->next != NULL) {
            if (cmp(temp->data, temp->next->data)) 
            {
                void *temp_data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = temp_data;

                b = 1;
            }
            temp = temp->next;
        }
    }

    return lst;
}


