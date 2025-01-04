#include "push_swap.h"

/* free stack */
void    ft_stackclear(t_stack **stack)
{
    t_stack  *current;
    t_stack  *temp;

    if (!stack)
            return ;
    current = *stack;
    while (current != NULL)
    {
            temp = current;
            current = current->next;
            free(temp);
    }
    *stack = NULL;
}

/* create a new node */
static t_stack	*ft_createnode(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

/* last node in stack */
// don't need might delete
t_stack *ft_lastnode(t_stack **stack)
{
    t_stack *temp;

    if (!*stack)
        return (NULL);
    temp = *stack;
    while (temp->next)
        temp = temp->next;
    return (temp);
}

/* add new node to end of stack */
static void	ft_stackadd_back(t_stack **stack, t_stack *node)
{
	t_stack	*temp;
    t_stack *last_node;

	if (!stack || !node)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
        node->prev = NULL;
		return ;
	}
    // for optimization, instead of pointing to the head
    temp = *stack;
    while (temp->next)
        temp = temp->next;
    last_node = temp;
	temp->next = node;
    node->prev = last_node;
}

void    stack_init(t_stack **a, int argc, char **argv)
{
    int i;
    int num;
    t_stack *node;

    i = 1;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        check_dup(a, num);
        node = ft_createnode(num);
        if (!node)
        {
            ft_stackclear(a);
            ft_printf("Failed to create new node.\n");
            exit(1);
        }
        ft_stackadd_back(a, node);
        i++;
    }
}