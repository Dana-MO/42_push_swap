#include "push_swap.h"

/* Stack Length */

int     ft_stacklen(t_stack **a)
{
    int len;
    t_stack *temp;

    len = 0;
    temp = *a;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return (len);
}

/* Swap */

// swap first 2 elements at the top of stack a

void    swap(t_stack **stack)
{
    int len;
    t_stack *head;
    t_stack *temp;

    temp = NULL;
    len = ft_stacklen(stack);
    // we could also do it like this
    // if (!*stack || !(*stack)->next)
    if (*stack == NULL || len == 1)
        return ;

    // *stack = head-next;
    //head = *stack; // aka the first node
    *stack = (*stack)->next; // now the second node is the head
    //head = *stack; // hold onto this
    head = (*stack)->prev;
    (*stack)->prev = NULL; // because nothing is before it
    if ((*stack)->next)
        temp = (*stack)->next;
    (*stack)->next = head; // points to what was previously the 1st node
    head = *stack;
    *stack = (*stack)->next; // move to new 2nd node
    (*stack)->prev = head; // first node
    (*stack)->next = temp;
    temp = *stack;
    if (len > 2)
    {
        *stack = (*stack)->next; // move to the 3rd node
        (*stack)->prev = temp;// the new 2nd node
        *stack = (*stack)->prev;
    }
    *stack = (*stack)->prev;
}