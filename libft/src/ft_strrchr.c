#include "libft.h"

char *ft_strrchr(const char *str, int n)
{
    char *res;

    res = (char *)str + ft_strlen(str);
    while (*res != n)
    {
        if (res == str)
            return NULL;
        res--;
    }
    return res;
}