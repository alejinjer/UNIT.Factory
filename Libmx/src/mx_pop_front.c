#include "libmx.h"

void mx_pop_front(t_list **head)
{
    t_list *temp = *head;

    if (!(*head) || !head)
        return;
    *head = temp->next;
    free(temp);
}
