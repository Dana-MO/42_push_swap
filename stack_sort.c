#include "push_swap.h"

/* sort 2 nodes */
static void    mini_sort(t_stack **a)
{
    t_stack *node_one;
    t_stack *node_two;

    if (!*a)
        return ;
    node_one = *a;
    node_two = node_one->next;
    if (node_one->value > node_two->value)
        sa(a);
}

/* sort a stack of 3 nodes */
static void    sort_three(t_stack **a)
{
    t_stack *node_two;
    t_stack *node_three;

    if (!*a)
        return ;
    mini_sort(a);
    node_two = (*a)->next;
    node_three = (*a)->next->next;
    if (node_two->value > node_three->value)
    {
        rra(a);
        mini_sort(a);
    }
}

/* sort a stack of 4 nodes */
static void     sort_four(t_stack **a, t_stack **b)
{
    t_stack *smallest_node;
    t_stack *node;

    if (!*a)
        return ;
    smallest_node = *a;
    node = (*a)->next;
    while (node)
    {
        if (smallest_node->value > node->value)
        {
            ra(a);
            smallest_node = node;
        }
        node = node->next;
    }
    pb(a, b);
    sort_three(a);
    pa(b, a);
}

void    sort(t_stack **a, t_stack **b)
{
    int len;
    
    len = ft_stacklen(a);
    if (len == 2)
        mini_sort(a);
    if (len == 3)
        sort_three(a);
    if (len == 4)
        sort_four(a, b);
}