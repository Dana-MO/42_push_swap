#include "push_swap.h"

/* Stack Length */
int     ft_stacklen(t_stack **stack)
{
    int len;
    t_stack *temp;

    len = 0;
    temp = *stack;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return (len);
}