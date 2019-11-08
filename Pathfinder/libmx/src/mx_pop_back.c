#include "libmx.h"

void mx_pop_back(t_list **head)
{
    t_list *temp = *head;

    if (!(*head) || !head)
        return;
    while (temp->next)
        temp = temp->next;
    free(temp);
}
