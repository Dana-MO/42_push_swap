#include "push_swap.h"

/* create a new node */
static t_stack	*ft_stacknew(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

/* add new node to end of stack */
static void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
    temp = *stack;
    while (temp->next)
        temp = temp->next;
	temp->next = new;
}

// why a pointer to a pointer **a 
void    stack_init(t_stack **a, int argc, char **argv)
{
    int i;
    int num;
    t_stack *node; //node is a pointer to a s_stack structure

    i = 1;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        node = ft_stacknew(num);
        if (!node)
        {
            ft_printf("Failed to create new node.\n");
            exit(1);
        }
        ft_stackadd_back(a, node);
        i++;
    }
}