#include "push_swap.h"

void    check_dup(t_stack *a, int num)
{
    if (a == NULL)
        return ;
    while (a)
    {
        if (a->value == num)
        {
            ft_printf("Error\n");
            exit(1);
        }
        a = a->next;
    }
}