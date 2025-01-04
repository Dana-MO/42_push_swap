#include "push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *new_head;
    t_stack *old_head;
    t_stack *last_node;

    if (!*stack || !(*stack)->next)
        return ;
    old_head = *stack;
    new_head = old_head->next;
    new_head->prev = NULL;
    // we could add a helper function for the last node
    last_node = new_head;
    while(last_node->next)
        last_node = last_node->next;
    last_node->next = old_head;
    old_head->prev = last_node;
    old_head->next = NULL;
    *stack = new_head;
}

void    ra(t_stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

// test function
void    rb(t_stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

// test function
void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}