#include <string.h>

char *ft_strchr(const char *str, int n)
{
    while (*str != n)
    {
        if (*str == '\0')
            return NULL;
        str++;
    }
    return (char *)str;
}