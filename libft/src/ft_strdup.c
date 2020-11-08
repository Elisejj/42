#include "libft.h"

char *ft_strdup(char *str)
{
    int str_len;
    char *res;
    int i;

    i = 0;
    str_len = ft_strlen(str);
    res = (char*) malloc((str_len + 1) * sizeof(char));
    if (!res)
        return NULL;
    while (str[i] != '\0')
    {
        res[i] = str[i];
        i++;
    }
    res[i] = '\0';
    return res;
}