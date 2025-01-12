#include "push_swap.h"

/* free array */
void    free_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

/* free array in case of error */
void    arr_error(char **arr, bool flag)
{
    if (flag)
        free_arr(arr);
    write(2, "Error\n", 6);
    exit(1);
}

/* check that all inputs are integers */
static int     check_int(char **arr)
{
    int i;
    int e;

    i = 0;
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

/* convert input to long */
static long	    ft_atol(const char *str)
{
	int	i;
	int	sign;
	long	result;

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

// clean up function
char    **validate_input(int argc, char **argv)
{
    int i;
    long    num;
    char    **arr;
    bool    flag;

    i = -1;
    num = 0;
    // is argv[1][0] correct
    if (argc == 2 && (argv[1][0] != '\0'))
    {
        arr = ft_split(argv[1], ' ');
        flag = true;
    } 
    else
        arr = argv + 1;
    if (argc > 1 && arr[0] && check_int(arr))
    {
        while (arr[++i])
        {
            num = ft_atol(arr[i]);
            if (num < INT_MIN || num > INT_MAX)
                arr_error(arr, flag);
        }
    }
    else
        arr_error(arr, flag);
    return (arr); 
}