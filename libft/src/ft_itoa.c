#include "libft.h"

int get_length(int num)
{
    int len;

    len = 0;
    if (num < 0)
    {
        len++;
        num = num * (-1);
    }
    while (num > 0)
    {
        len++;
        num = num / 10;
    }
    return len;
}

char *ft_itoa(int num)
{
    char *str;
    int i;

    i = get_length(num);
    str = (char*) malloc((i + 1) * sizeof(char));
    if (!str)
        return NULL;
    if (num == -2147483648)
    {
        ft_strlcpy(str, "-2147483648", 12);
        return str;
    }
    i--;
    str[i] = '\0';
    if (num == 0)
    {
        str[0] = 48;
        return str;
    }
    if (num < 0)
    {
        str[0] = '-';
        num = num * (-1);
    }
    while (num > 0)
    {
        str[i] = 48 + (num % 10);
        num = num / 10;
        i--;
    }
    return str;
}