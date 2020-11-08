#include "libft.h"

void *ft_memset(void *s, int ch, size_t n)
{
    size_t i;
    unsigned char *c;

    c = (unsigned char*) s;

    i = 0;
    while (i < n)
    {
        c[i] = ch;
        i++;
    }
    return (void*) c;
}
