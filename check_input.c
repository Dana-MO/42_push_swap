#include "push_swap.h"
#include <limits.h>
// check if limits.h is allowed

/* check that all inputs are integers */

int     check_int(int argc, char **argv)
{
    int i;
    int e;

    i = 1;
    while (i < argc)
    {
        e = 0;
        while (argv[i][e])
        {
            if (argv[i][e] == '+' || argv[i][e] == '-')
                e++;
            if (!ft_isdigit(argv[i][e]))
                return (0);
            e++;
        }
        if (argv[i][e] != '\0')
            return (0);
        i++;
    }
    return (1);
}

/* convert input to long */

long	ft_atol(const char *str)
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

void    validate_input(int argc, char **argv)
{
    int     i;
    long     num;

    i = 1;
    num = 0;
    // if all inputs are integers, check they are within INT_MAX and INT_MIN
    if (argc > 1 && (argv[1][0] != '\0') && check_int(argc, argv))
    {
        while (i < argc)
        {
            num = ft_atol(argv[i]);
            if (num < INT_MIN || num > INT_MAX)
            {
                write(2, "Error\n", 6);
                exit(1);
            }
            i++;
        }
    }
    else
    {
        write(2, "Error\n", 6);
        exit(1);
    }
}