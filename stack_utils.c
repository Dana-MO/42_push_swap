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

/* last node in stack */
// don't need might delete
t_stack *ft_lastnode(t_stack **stack)
{
    t_stack *temp;

    if (!*stack)
        return (NULL);
    temp = *stack;
    while (temp->next)
        temp = temp->next;
    return (temp);
}

/* places node with smallest value at the top of the stack*/
void    smallest_node(t_stack **stack)
{
    t_stack *smallest;
    t_stack *node;
    int rotations;

    rotations = 0;
    smallest = *stack;
    node = (*stack)->next;
    while (node)
    {
        if (node->value < smallest->value)
        {
            smallest = node;
            rotations = 0;
        }
        node = node->next;
        rotations++;
    }
    while (*stack != smallest)
    {
        if (rotations > 0)
            ra(stack);
        else
            rra(stack);
    }
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