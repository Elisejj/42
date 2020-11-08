#include "libft.h"

char *ft_substr(char const *s, int start, int len)
{
    char *res;
    int i;
    
    i = 0;
    res = (char*) malloc((len + 1) * sizeof(char));
    if (!res)
        return NULL;
    while (s[start] && i < len)
    {
        res[i] = s[start];
        i++;
        start++;
    }
    res[i] = '\0';
    return res;
}