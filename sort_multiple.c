#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
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

static void	move_a_to_b(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

void	sort_multiple(t_stack **a, t_stack **b, int stack_len)
{
	t_stack	*cheapest_node;

	cheapest_node = NULL;
	if (!*a)
		return ;
	pb(a, b);
	if (--stack_len > 3)
		pb(a, b);
	while (--stack_len > 3)
	{
		cheapest_node = init_a_nodes(*a, *b);
		move_a_to_b(a, b, cheapest_node);
	}
	sort_three(a);
	while (*b)
	{
		init_b_nodes(*a, *b);
		prep_for_push(a, (*b)->target_node, 'a');
		pa(b, a);
	}
	min_on_top(a);
}
