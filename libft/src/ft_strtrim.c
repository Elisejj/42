#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    int s_len;
    char *res;

    if (!s1 || !set)
        return 0;
    while (*s1 && ft_strchr(set, *s1))
        s1++;
    s_len = ft_strlen(s1);
    while (s_len && ft_strchr(set, s1[s_len]))
        s_len--;
    res = ft_substr((char*)s1, 0, s_len + 1);
    return res;
}