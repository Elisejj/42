#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *res;
    int s_len;
    int i;

    if (!s || !f)
        return NULL;
    i = 0;
    s_len = ft_strlen(s);
    res = (char*) malloc((s_len + 1) * sizeof(char));
    if (!res)
        return NULL;
    while (i < s_len)
    {
        res[i] = f(i, s[i]);
        i++;
    }
    res[i] = '\0';
    return res;
}