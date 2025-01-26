#include "push_swap.h"

/* Free array from split function */

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/* Free array if necessary, print error message */

void	error_msg(char **arr, bool is_dynamic)
{
	if (is_dynamic)
		free_arr(arr);
	write(2, "Error\n", 6);
	exit(1);
}
