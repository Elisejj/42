#include "libft.h"
#include <unistd.h>

void ft_putnbr_fd(int num, int fd)
{
    if (num == -2147483648)
        ft_putstr_fd("-2147483648", fd);
    else if (num < 0)
    {
        ft_putchar_fd('-', fd);
        ft_putnbr_fd(num * (-1), fd);
    }
    else if (num >= 10)
    {
        ft_putnbr_fd(num / 10, fd);
        ft_putchar_fd(num % 10 + '0', fd);
    }
    else
    {
        ft_putchar_fd(num + '0', fd);
    }
}