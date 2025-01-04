#include "push_swap.h"

/* Stack Length */
// we might not end up needing this function
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

/* Swap first 2 elements at the top of a stack */

void    swap(t_stack **stack)
{
    int len;
    t_stack *new_head;
    t_stack *old_head;
    t_stack *third_node;

    third_node = NULL;
    len = ft_stacklen(stack);
    // we could also do it like this
    // if (!*stack || !(*stack)->next)
    if (*stack == NULL || len == 1)
        return ;

    old_head = *stack;
    new_head = (*stack)->next;
    *stack = new_head;
    new_head->prev = NULL;
    if (new_head->next)
    {
        third_node = new_head->next;
        third_node->prev = old_head;
    }
    new_head->next = old_head;
    old_head->prev = new_head;
    old_head->next = third_node;
}

void    sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

// test if it works
void    sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

// test if it works
void    ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}