#include "libft.h"

void* ft_memcpy(void* dest, const void* source, size_t n)
{
    size_t i;
    unsigned char *uc_dest;
    unsigned char *uc_source;

    uc_dest = (unsigned char *)dest;
    uc_source = (unsigned char *)source;
    i = 0;
    if (n && (uc_dest || uc_source)){
    while (i < n)
        {
            uc_dest[i] = uc_source[i];
            i++;
        }
        return (void*) uc_dest;
    }
    return (void*) uc_dest;
}