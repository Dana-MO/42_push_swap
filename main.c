#include "libft/libft.h"

int main(int argc, char **argv)
{
    int     i;

    i = 1;
    if (argc > 1)
    {
        while (i < argc)
        {
            ft_printf("Number: %s\n", argv[i]);
            i++;
        }
    }
    else
        write(2, "Error\n", 6);
    return (0);
}