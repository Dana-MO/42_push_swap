#include "push_swap.h"

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
    while (temp)
    {
        printf("Number: %d\n", temp->value);
        temp = temp->next;
    }
    ft_stackclear(&a);
    return (0);
}