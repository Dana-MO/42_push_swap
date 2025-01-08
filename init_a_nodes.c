#include "push_swap.h"

void       current_index(t_stack *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return ;
    median = ft_stacklen(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        ++i;
    }
}

static void     set_target_a(t_stack *a, t_stack *b)
{
    t_stack *current_b;
    t_stack *target_node;
    int    best_match_index;

    while (a)
    {
        best_match_index = INT_MIN;
        current_b = b;
        while (current_b)
        {
            if (current_b->value < a->value
                && current_b->value > best_match_index)
            {
                best_match_index = current_b->value;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (best_match_index == INT_MIN)
            a->target_node = find_max(b);
        else
            a->target_node = target_node;
        a = a->next;
    }
}

// come back to understand this part
static void     cost_analysis(t_stack *a, t_stack *b)
{
    int len_a;
    int len_b;

    len_a = ft_stacklen(a);
    len_b = ft_stacklen(b);
    while (a)
    {
        a->push_cost = a->index;
        if (!(a->above_median))
            a->push_cost = len_a - (a->index);
        // I don't understand this part
        if (!(a->target_node->above_median))
            a->push_cost += a->target_node->index;
        else
            a->push_cost += len_b - (a->target_node->index);
        a = a->next;
    }
}

void    set_cheapest(t_stack *stack)
{
    int     cheapest_value;
    t_stack *cheapest_node;

    if (!stack)
        return ;
    cheapest_value = INT_MAX;
    while (stack)
    {
        if (stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    cheapest_node->cheapest = true;
}

/* initiate nodes in stack a */
void    init_a_nodes(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_analysis(a, b);
    set_cheapest(a);
}