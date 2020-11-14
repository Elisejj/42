#include "libft.h"
#include "stdio.h"

char* ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    if (little[0] == '\0')
        return (char*)big;
    while (i < len && big[i] != '\0')
    {
        if (big[i] == little[0])
        {
            j = 1;
            while (big[i + j] == little[j] && i + j < len && little[j] != '\0')
            {
                j++;
                if (little[j] == '\0')
                    return (char*)&big[i];
            }
        }
        i++;
    }
    return NULL;
}
