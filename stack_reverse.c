#include "push_swap.h"

void reverse(t_stack **stack)
{
    t_stack *new_head;
    t_stack *old_head;

    if (!*stack || !(*stack)->next)
        return ;
    old_head = *stack;
    // we could add a helper function for the last node
    new_head = *stack;
    while (new_head->next)
        new_head = new_head->next;
    new_head->next = old_head;
    new_head->prev->next = NULL;
    new_head->prev = NULL;
    old_head->prev = new_head;
    *stack = new_head;
}

void    rra(t_stack **a)
{
    reverse(a);
    write(1, "rra\n", 4);
}

// test function
void    rrb(t_stack **b)
{
    reverse(b);
    write(1, "rrb\n", 4);
}

// test function
void    rrr(t_stack **a, t_stack **b)
{
    reverse(a);
    reverse(b);
    write(1, "rrr\n", 4);
}