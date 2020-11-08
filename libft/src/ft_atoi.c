#include <unistd.h>

int ft_atoi(const char *str)
{
    int i;
    int num;
    int is_negative;

    num = 0;
    is_negative = 1;
    i = 0;
    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
        i++;
    
    if (str[i] == '-')
        is_negative = -1;
    if ((str[i] == '+' && (str[i + 1] == '+' || str[i + 1] == '-')) || (str[i] == '-' && (str[i + 1] == '+' || str[i + 1] == '-')))
        return 0;
    while (str[i] == '-' || str[i] == '+')
    {
        if (is_negative == -1 && str[i] == '+')
            return 0;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - 48);
        i++;
    }
    return num * is_negative;
}
