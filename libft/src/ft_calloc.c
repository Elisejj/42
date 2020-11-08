#include "libft.h"

void *ft_calloc(size_t elem_count, size_t elem_size)
{
    void *arr;

    arr = malloc(elem_count * elem_size);
    if (arr)
        ft_memset(arr, 0, elem_count * elem_size);
    return arr;
}