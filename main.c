#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack *temp = stack;
	printf("Stack (forward): ");
	while (temp)
	{
		printf("%d -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
}

void	print_stack_reverse(t_stack *stack)
{
	t_stack *temp = stack;
	// Find the last node
	while (temp && temp->next)
		temp = temp->next;
	printf("Stack (backward): ");
	while (temp)
	{
		printf("%d -> ", temp->value);
		temp = temp->prev;
	}
	printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp_a;
	t_stack	*temp_b;
	char	**arr;
	
	a = NULL;
	b = NULL;
	arr = NULL;
	
	if (argc <= 1)
		error_msg(NULL, false);
	arr = validate_input(argc, argv);
	stack_init(&a, argc, arr);
	
	// print stacks before change
	printf("Stacks Before\n");
	temp_a = a;
	print_stack(temp_a);
	temp_b = b;
	print_stack(temp_b);
	
	// print stacks after sorting
	printf("\nSorted\n");
	if (!check_sort(a))
		sort_stack(&a, &b);
	temp_a = a;
	print_stack(temp_a);
	temp_b = b;
	print_stack(temp_b);
	
	// print stack in reverse to make sure prev is correct
	printf("\nReverse Stacks\n");
	print_stack_reverse(temp_a);
	print_stack_reverse(temp_b);
	
	// this function might be moved to a different file than stack init
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}
