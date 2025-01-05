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

void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);

void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);

void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

void    pa(t_stack **b, t_stack **a);
void    pb(t_stack **a, t_stack **b);

#endif