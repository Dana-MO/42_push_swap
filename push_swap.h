#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct n_stack
{
	int             value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct n_stack	*target_node;
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

int     stack_len(t_stack *stack);
t_stack    *find_max(t_stack *stack);
t_stack    *find_min(t_stack *stack);

void    check_sort(t_stack *a);
void    sort(t_stack **a, t_stack **b);
void    sort_three(t_stack **a);
void    sort_multiple(t_stack **a, t_stack **b, int len);

void       current_index(t_stack *stack);
t_stack    *init_a_nodes(t_stack *a, t_stack *b);
void    init_b_nodes(t_stack *a, t_stack *b);
void     min_on_top(t_stack **a);

#endif