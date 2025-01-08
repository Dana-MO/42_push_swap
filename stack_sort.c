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

/* sort a stack of 4 nodes and above */
static void     sort_four(t_stack **a, t_stack **b, int len)
{
    if (!*a)
        return ;
    while (len > 3)
    {
        smallest_node(a);
        pb(a, b);
        len--;
    }
    sort_three(a);
    while (*b)
        pa(b, a);
}

/* check if stack is sorted */
static void    check_sort(t_stack **a)
{
    t_stack *node;

    if (!*a)
        exit(1);
    node = *a;
    while (node)
    {
        if (node->next != NULL && node->value > node->next->value)
            break;            
        node = node->next;
    }
    if (node == NULL)
        exit(0);
}

void    sort(t_stack **a, t_stack **b)
{
    int len;

    check_sort(a);
    len = ft_stacklen(a);
    if (len == 2)
        mini_sort(a);
    else if (len == 3)
        sort_three(a);
    else if (len == 4)
        sort_four(a, b, len);
    else
        sort_multiple(a, b);
}