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

/* Check that all inputs are integers */

static int	check_int(char **arr)
{
	int	i;
	int	e;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
	{
		e = 0;
		while (arr[i][e])
		{
			if (arr[i][e] == '+' || arr[i][e] == '-')
				e++;
			if (!ft_isdigit(arr[i][e]))
				return (0);
			e++;
		}
		if (arr[i][e] != '\0')
			return (0);
		i++;
	}
	return (1);
}

/* Convert string to long int */

static long	ft_atol(const char *str)
{
	long	result;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (sign == -1 || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/* Check that all inputs are integers within the range of an int */

char	**validate_input(int argc, char **argv)
{
	long	num;
	bool	is_dynamic;
	char	**arr;
	int		i;

	i = -1;
	num = 0;
	is_dynamic = false;
	if (argc == 2 && argv[1] && (argv[1][0] != '\0'))
	{
		arr = ft_split(argv[1], ' ');
		is_dynamic = true;
	}
	else
		arr = argv + 1;
	if (!arr || !arr[0] || !check_int(arr))
		error_msg(arr, is_dynamic);
	while (arr[++i])
	{
		num = ft_atol(arr[i]);
		if (num < INT_MIN || num > INT_MAX)
			error_msg(arr, is_dynamic);
	}
	return (arr);
}
