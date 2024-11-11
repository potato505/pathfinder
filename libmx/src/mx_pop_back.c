#include"../inc/libmx.h"

void mx_pop_back(t_list **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }
    if ((*head)->next == NULL) 
    {
        free(*head);
        *head = NULL;
    }
    else {
        t_list *temp = *head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp->next = NULL;
    } 
}


