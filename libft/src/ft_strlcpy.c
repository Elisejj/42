#include "libft.h"

size_t ft_strlcpy(char* dest, char* src, size_t n)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    if (!dest || !src)
        return 0;
    if (n && (dest || src))
    {
        while (n - 1 > i && src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return ft_strlen(src);
}
