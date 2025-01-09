#include "push_swap.h"

/* Stack Length */
int     stack_len(t_stack *stack)
{
    int len;

    len = 0;
    while (stack != NULL)
    {
        len++;
        stack = stack->next;
    }
    return (len);
}

/* find node with largest value */
t_stack    *find_max(t_stack *stack)
{
    t_stack *max;
    t_stack *node;

    max = stack;
    node = stack->next;
    while (node)
    {
        if (node->value > max->value)
            max = node;
        node = node->next;
    }
    return (max);
}

/* find node with smallest value */
t_stack    *find_min(t_stack *stack)
{
    t_stack *min;
    t_stack *node;

    min = stack;
    node = stack->next;
    while (node)
    {
        if (node->value < min->value)
            min = node;
        node = node->next;
    }
    return (min);
}