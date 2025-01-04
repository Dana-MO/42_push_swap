#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>

typedef struct n_stack
{
	int             value;
	struct n_stack	*next;
	struct n_stack	*prev;
}		t_stack;

void    validate_input(int argc, char **argv);
void    stack_init(t_stack **a, int argc, char **argv);
void    check_dup(t_stack **a, int num);
void    ft_stackclear(t_stack **stack);

#endif