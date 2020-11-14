#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_lst;
    t_list *tmp;

    tmp = ft_lstnew(f(lst->content));
    if (!tmp)
    {
        ft_lstclear(&lst, del);
        return NULL;
    }
    new_lst = tmp;
    lst = lst->next;
    while (lst)
    {
        tmp = ft_lstnew(f(lst->content));
        if (!tmp)
        {
            ft_lstclear(&lst, del);
        }
        lst = lst->next;
        ft_lstadd_back(&new_lst, tmp);
    }
    return new_lst;
}