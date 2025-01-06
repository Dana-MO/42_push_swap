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

/* places the node with the smallest value at the top of the stack*/
void    smallest_node(t_stack **stack)
{
    t_stack *smallest;
    t_stack *node;

    smallest = *stack;
    node = (*stack)->next;
    while (node)
    {
        if (smallest->value > node->value)
            smallest = node;
        node = node->next;
    }
    node = *stack;
    if (smallest->next == NULL)
        rra(stack);
    else
    {
        while (node)
        {
            if (node->value == smallest->value)
                break;
            node = node->next;
            ra(stack);
        }
    }
}