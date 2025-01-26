#include "push_swap.h"

/* Create new node */

static t_stack	*ft_createnode(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->push_cost = 0;
	node->above_median = false;
	node->cheapest = false;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/* Add new node to end of stack */

static void	ft_stackadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node;
	new_node->prev = last_node;
}

/* Check for duplicate integers */

static void	check_dup(t_stack **a, int num, char **arr, bool is_dynamic)
{
	t_stack	*temp;

	temp = *a;
	if (temp == NULL)
		return ;
	while (temp)
	{
		if (temp->value == num)
		{
			ft_stackclear(a);
			error_msg(arr, is_dynamic);
		}
		temp = temp->next;
	}
}

/* Create a stack of nodes */

void	stack_init(t_stack **a, int argc, char **arr)
{
	int		i;
	int		num;
	t_stack	*node;
	bool	is_dynamic;

	i = 0;
	is_dynamic = false;
	if (argc == 2)
		is_dynamic = true;
	while (arr[i])
	{
		num = ft_atoi(arr[i]);
		check_dup(a, num, arr, is_dynamic);
		node = ft_createnode(num);
		if (!node)
		{
			ft_stackclear(a);
			break ;
		}
		ft_stackadd_back(a, node);
		i++;
	}
	if (is_dynamic)
		free_arr(arr);
}
