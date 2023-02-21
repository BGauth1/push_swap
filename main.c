#include <stdio.h>
#include <stdlib.h>

void    parse_args(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            if (av[i][j] < '0' || av[i][j] > '9')
            {
                printf("Error.\n");
                exit(1);
            }
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (1);
    parse_args(ac, av);
}