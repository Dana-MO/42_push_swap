#include "push_swap.h"

/* Rotate down by 1 all nodes in a stack, last node becomes first */

static void	reverse(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*old_head;

	if (!*stack || !(*stack)->next)
		return ;
	old_head = *stack;
	new_head = *stack;
	while (new_head->next)
		new_head = new_head->next;
	new_head->next = old_head;
	new_head->prev->next = NULL;
	new_head->prev = NULL;
	old_head->prev = new_head;
	*stack = new_head;
}

/* Shift down all nodes of `stack a` by 1, last node becomes first */

void	rra(t_stack **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

/* Shift down all nodes of `stack b` by 1, last node becomes first */

void	rrb(t_stack **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

/* Shift down by 1 all nodes in both stacks, last nodes become first */

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
