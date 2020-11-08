#include "libft.h"

size_t ft_strlcpy(char* dest, char* src, size_t n)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    if (!dest || !src || n < 0)
        return ft_strlen(dest);
    if (n && (dest || src))
    {
        while (src[j] != '\0')
            j++;
        if (n == 0)
            return j;
        while (i < n - 1 && src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return j;
}
