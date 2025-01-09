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

/* check for duplicate integers */
void    check_dup(t_stack **a, int num)
{
    t_stack     *temp;

    temp = *a;
    if (temp == NULL)
        return ;
    while (temp)
    {
        if (temp->value == num)
        {
            ft_stackclear(a);
            ft_printf("Error\n");
            exit(1);
        }
        temp = temp->next;
    }
}

void    stack_init(t_stack **a, char **arr)
{
    int i;
    int num;
    t_stack *node;

    i = 0;
    while (arr[i])
    {
        num = ft_atoi(arr[i]);
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