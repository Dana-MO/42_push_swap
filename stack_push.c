#include "push_swap.h"

void ft_stackadd_top(t_stack **stack, t_stack *node)
{
    t_stack *temp;

    if (stack && node)
    {
        node->next = *stack;
        *stack = node;
    }
    if ((*stack)->next)
    {
        temp = *stack;
        temp = temp->next;
        temp->prev = *stack;
    }
}

void    push(t_stack **stack_one, t_stack **stack_two)
{
    t_stack *node;

    if (!*stack_one)
        return ;
    node = *stack_one;
    *stack_one = (*stack_one)->next;
    (*stack_one)->prev = NULL;
    ft_stackadd_top(stack_two, node);
}

// take 1st element at the top of `stack b` to top of `stack a`
void    pa(t_stack **b, t_stack **a)
{
    push(b, a);
    write(1, "pa\n", 3);
}

// take 1st element at the top of `stack a` to top of `stack b`
void    pb(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}