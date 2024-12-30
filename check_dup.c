#include "push_swap.h"

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