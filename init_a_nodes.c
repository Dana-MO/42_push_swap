#include "push_swap.h"

/* Assign an index value to each node */

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
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

/* Assign each node in 'stack a' target node from stack b */

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	int		best_match_index;

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

/* Assign each node in 'stack a' push cost */

static void	cost_analysis(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

/* Return node with cheapest push cost */

t_stack	*set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	int		cheapest_value;

	if (!stack)
		return (NULL);
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
	return (cheapest_node);
}

/* Initiate nodes in 'stack a', return node with cheapest push cost */

t_stack	*init_a_nodes(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;

	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis(a, b);
	cheapest = set_cheapest(a);
	return (cheapest);
}
