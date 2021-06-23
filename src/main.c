#include <philo_header.h>

void    check_struct(t_data *data)
{
    printf(RED "===== DATA =====\n");
    printf(YELLOW "count        %d\n", data->count_philo);
    printf("die          %d\n", data->die);
    printf("eat          %d\n", data->eat);
    printf("sleep        %d\n", data->sleep);
    printf("must_eat     %d\n\n" RESET, data->must_eat);
}

int main(int argc, char **argv)
{
    t_data  data;

    if (argc == 5 || argc == 6)
    {
        if (check_data(argv, &data))
            printf("ok\n");
        check_struct(&data);
    }
    else
        print_message(&data.msg, ERROR_COUNT);
    return (0);
}
