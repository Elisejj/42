#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *tmp;

    tmp = malloc(sizeof(t_list));
    if (tmp)
    {
        tmp->next = NULL;
        tmp->content = content;
    }
    return tmp;
}