#include "ft_printf.h"

void put_sign(p_struct specification)
{
    if (specification.minus != 1 && specification.plus == 1)
        ft_putchar_fd('+', 1);
    else if (specification.minus == 1)
        ft_putchar_fd('-', 1);
}

int get_num_len(p_struct specification, int num)
{
    int len;

    len = 0;
    if (num == 0)
        len = 1;
    if (specification.minus == 1)
        len++;
    else if (specification.plus == 1)
        len++;
    while (num)
    {
        num = num / 10;
        len++;
    }
    if (specification.dot == 1 && specification.precision == 0)
        len = 0;
    return (len);
}

int get_zero_len(p_struct specification, int number_len)
{
    int zero_len;

    zero_len = specification.precision - (number_len - (specification.plus || specification.minus));
    if (zero_len < 0)
        zero_len = 0;
    return (zero_len);
}

int get_space_len(p_struct specification, int number_len, int zero_len)
{
    int space_len;

    space_len = specification.width - (number_len + zero_len);
    if (space_len < 0)
        space_len = 0;
    return (space_len);
}
