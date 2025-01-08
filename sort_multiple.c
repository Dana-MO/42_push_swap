#include "push_swap.h"

t_stack     *get_cheapest(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

static void rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
    while (*b != cheapest_node->target_node
        && *a != cheapest_node)
        rr(a, b);
    current_index(*a);
    current_index(*b);
}

static void rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
    while (*b != cheapest_node->target_node
        && *a != cheapest_node)
        rrr(a, b);
    current_index(*a);
    current_index(*b);
}

void    prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
    while (*stack != top_node)
    {
        if (stack_name == 'a')
        {
            if (top_node->above_median)
                ra(stack);
            else
                rra(stack);
        }
        else if (stack_name == 'b')
        {
            if (top_node->above_median)
                rb(stack);
            else
                rrb(stack);
        }
    }
}

static void     move_a_to_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest_node;

    cheapest_node = get_cheapest(*a);
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
        rotate_both(a, b, cheapest_node);
    else if (!(cheapest_node->above_median)
        && !(cheapest_node->target_node->above_median))
        rev_rotate_both(a, b, cheapest_node);
    // have no idea what the hell these are
    prep_for_push(a, cheapest_node, 'a');
    prep_for_push(b, cheapest_node->target_node, 'b');
    pb(a, b);
}

static void     move_b_to_a(t_stack **a, t_stack **b)
{
    prep_for_push(a, (*b)->target_node, 'a');
    pa(b, a);
}

static void     min_on_top(t_stack **a)
{
    while ((*a)->value != find_min(*a)->value)
    {
        if (find_min(*a)->above_median)
            ra(a);
        else
            rra(a);
    }
}

void    sort_multiple(t_stack **a, t_stack **b, int stack_len)
{
    if (!*a)
        return ;
    if (stack_len-- > 3)
        pb(a, b);
    if (stack_len-- > 3)
        pb(a, b);
    // add a check to see if stack is sorted
    while (stack_len-- > 3)
    {
        init_a_nodes(*a, *b);
        move_a_to_b(a, b);
    }
    sort_three(a);
    while(*b)
    {
        init_b_nodes(*a, *b);
        move_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}