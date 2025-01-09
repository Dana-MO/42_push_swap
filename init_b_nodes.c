#include "push_swap.h"

/* assign each node in 'stack b' a target from 'stack a' */
static void set_target_b(t_stack *a, t_stack *b)
{
    t_stack *current_a;
    t_stack *target_node;
    int     best_match_index;

    while (b)
    {
        best_match_index = INT_MAX;
        current_a = a;
        while (current_a)
        {
            if (current_a->value > b->value
                && current_a->value < best_match_index)
            {
                best_match_index = current_a->value;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match_index == INT_MAX)
            b->target_node = find_min(a);
        else
            b->target_node = target_node;
        b = b->next;
    }
}

void    init_b_nodes(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_b(a, b);
}