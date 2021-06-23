#include <philo_header.h>

int ft_isdigit(int c)
{
    if (48 <= c && c <= 57)
        return (TRUE);
    return (FALSE);
}

double isnumber(char *number)
{
    int i;
    int res;

    i = 0;
    res = -1;
    while (number[i] != '\0')
    {
        if (!ft_isdigit(number[i]))
            return (FALSE);
        i++;
    }
    return (ft_atoi(number));
}
