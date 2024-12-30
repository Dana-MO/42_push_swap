#include "push_swap.h"

int     main(int argc, char **argv)
{
    t_stack     *a;
    t_stack     *b;

    a = NULL;
    b = NULL;
    // clean up validate input file
    validate_input(argc, argv);
    // if an error occurs or if we are done stack a needs to be freed
    stack_init(&a, argc, argv);
    while (a)
    {
        printf("Number: %d\n", a->value);
        a = a->next;
    }
    return (0);
}