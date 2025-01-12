#include "push_swap.h"

/* Swap first 2 nodes at the top of the stack */

static void	swap(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*old_head;
	t_stack	*third_node;

	third_node = NULL;
	if (!*stack || !(*stack)->next)
		return ;
	old_head = *stack;
	new_head = (*stack)->next;
	*stack = new_head;
	new_head->prev = NULL;
	if (new_head->next)
	{
		third_node = new_head->next;
		third_node->prev = old_head;
	}
	new_head->next = old_head;
	old_head->prev = new_head;
	old_head->next = third_node;
}

/* Swap first 2 elements at the top of `stack a`*/

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/* Swap first 2 elements at the top of `stack b`*/

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/* Swap first 2 elements at the top of both stacks*/

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
