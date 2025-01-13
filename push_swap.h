#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

/* Check Input and Initiate Stack*/

int		check_sort(t_stack *a);
char	**validate_input(int argc, char **argv);
void	stack_init(t_stack **a, int argc, char **arr);

/* Free Array/Stack and Return Error Message */

void	free_arr(char **arr);
void	ft_stackclear(t_stack **stack);
void	error_msg(char **arr, bool is_dynamic);

/* Stack Commands */

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);

/* Stack Utilities */

int		stack_len(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);

/* Sort Stack */

void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_multiple(t_stack **a, t_stack **b, int len);

/* Initiate Nodes for Sorting */

t_stack	*init_a_nodes(t_stack *a, t_stack *b);
void	init_b_nodes(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);
void	min_on_top(t_stack **a);

#endif
