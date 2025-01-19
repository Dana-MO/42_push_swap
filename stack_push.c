#include "push_swap.h"

/* Move top 1st node from one stack to another */

static void	push(t_stack **stack_one, t_stack **stack_two)
{
	t_stack	*node;

	if (!*stack_one)
		return ;
	node = *stack_one;
	if ((*stack_one)->next)
	{
		*stack_one = (*stack_one)->next;
		(*stack_one)->prev = NULL;
	}
	else
		*stack_one = NULL;
	node->next = *stack_two;
	*stack_two = node;
	if ((*stack_two)->next)
		(*stack_two)->next->prev = *stack_two;
}

/* Move top 1st node in `stack b` to top of `stack a` */

void	pa(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

/* Move top 1st node in `stack a` to top of `stack b` */

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
