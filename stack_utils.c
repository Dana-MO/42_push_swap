#include "push_swap.h"

/* Stack Length */
int     ft_stacklen(t_stack **a)
{
    int len;
    t_stack *temp;

    len = 0;
    temp = *a;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return (len);
}