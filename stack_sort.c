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
// may come back to clean function 
static void    sort_three(t_stack **a)
{
    t_stack *node_one;
    t_stack *node_two;
    t_stack *node_three;

    if (!*a)
        return ;
    node_one = *a;
    node_two = (*a)->next;
    node_three = (*a)->next->next;
    if (node_one->value > node_two->value && node_one->value > node_three->value)
        ra(a);
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
    if (!*a)
        return ;
    smallest_node(a);
    pb(a, b);
    sort_three(a);
    pa(b, a);
}

/* sort a stack of 5 nodes */
static void     sort_five(t_stack **a, t_stack **b)
{
    if (!*a)
        return ;
    smallest_node(a);
    pb(a, b);
    smallest_node(a);
    pb(a, b);
    sort_three(a);
    pa(b, a);
    pa(b, a);
}

/* sort a stack of 6 nodes */
static void     sort_six(t_stack **a, t_stack **b)
{
    if (!*a)
        return ;
    smallest_node(a);
    pb(a, b);
    smallest_node(a);
    pb(a, b);
    smallest_node(a);
    pb(a, b);
    sort_three(a);
    pa(b, a);
    pa(b, a);
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
    if (len == 5)
        sort_five(a, b);
    if (len == 6)
        sort_six(a, b);
}