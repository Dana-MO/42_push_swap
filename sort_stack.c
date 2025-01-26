#include "push_swap.h"

/* Sort 2 nodes */

static void	mini_sort(t_stack **a)
{
	t_stack	*node_one;
	t_stack	*node_two;

	if (!*a)
		return ;
	node_one = *a;
	node_two = node_one->next;
	if (node_one->value > node_two->value)
		sa(a);
}

/* Sort 3 nodes */

void	sort_three(t_stack **a)
{
	t_stack	*node_one;
	t_stack	*node_two;
	t_stack	*node_three;

	if (!*a)
		return ;
	node_one = *a;
	node_two = (*a)->next;
	node_three = (*a)->next->next;
	if (node_one->value > node_two->value
		&& node_one->value > node_three->value)
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

/* Sort stack based on number of nodes in stack */

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 2)
		mini_sort(a);
	else if (len == 3)
		sort_three(a);
	else
		sort_multiple(a, b, len);
}
