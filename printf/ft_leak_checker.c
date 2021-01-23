#include "ft_printf.h"

void ft_leak_checker(p_struct *specification, void *obj)
{
    if (specification->leak)
        free(obj);
}