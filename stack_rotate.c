#include "push_swap.h"

/* Rotate up by 1 all nodes in a stack, first node becomes last */

static void	rotate(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*old_head;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	old_head = *stack;
	new_head = old_head->next;
	new_head->prev = NULL;
	last_node = new_head;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = old_head;
	old_head->prev = last_node;
	old_head->next = NULL;
	*stack = new_head;
}

/* Shift up all nodes of `stack a` by 1, first node becomes last */

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/* Shift up all nodes of `stack b` by 1, first node becomes last */

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/* Shift up by 1 all nodes of both stacks, first nodes become last */

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
