#include "push_swap.h"

void print_stack(t_stack *stack)
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

void print_stack_reverse(t_stack *stack)
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

int     main(int argc, char **argv)
{
    t_stack     *a;
    t_stack     *b;
    t_stack     *temp;

    a = NULL;
    b = NULL;
    // clean up validate input file
    validate_input(argc, argv);
    stack_init(&a, argc, argv);
    temp = a;
    print_stack(temp);
    printf("Reverse\n");
    rra(&a);
    temp = a;
    print_stack(temp);
    temp = a;
    print_stack_reverse(temp);
    // while (temp)
    // {
    //     printf("Number: %d\n", temp->value);
    //     temp = temp->next;
    // }
    ft_stackclear(&a);
    return (0);
}