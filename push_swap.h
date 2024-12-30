#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct n_stack
{
	int             value;
	struct n_stack	*next;
}		t_stack;

void    validate_input(int argc, char **argv);
void    stack_init(t_stack **a, int argc, char **argv);
#endif