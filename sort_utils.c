#include "push_swap.h"

/* Check if stack is sorted */

int	check_sort(t_stack *a)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->next != NULL && a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

/* Find node with largest value */

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*node;

	max = stack;
	node = stack->next;
	while (node)
	{
		if (node->value > max->value)
			max = node;
		node = node->next;
	}
	return (max);
}

/* Find node with smallest value */

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*node;

	min = stack;
	node = stack->next;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

/* Check that integer with smallest values is at top of stack */

void	min_on_top(t_stack **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
