#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    unsigned char *c;

    c = (unsigned char*)s;
    ft_memset(c, '\0', n);
}