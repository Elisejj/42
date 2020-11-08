#include "libft.h"

void *ft_memmove(void *dest, void *src, size_t n)
{
    size_t i;
    unsigned char* c1;
    unsigned char* c2;

    c1 = (unsigned char*)dest;
    c2 = (unsigned char*)src;
    if (n && (src || dest))
    {
        if (src < dest)
        {
            i = n;
            while (i)
            {
                i--;
                c1[i] = c2[i];
            }
        }
        else
        {
            i = 0;
            while (i < n)
            {
                c1[i] = c2[i];
                i++;
            }
        }
    }
    return (void*)c1;
}