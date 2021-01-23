#include "ft_printf.h"

int s_handler(p_struct *specification, va_list argptr)
{
    char *string;

    string = va_arg(argptr, char*);
    if (!string)
        string = "(null)";
    if (s_processor(specification, string) == -1)
        return (-1);
    return (1);
}

int di_handler(p_struct *specification, va_list argptr)
{
    int num;

    num = va_arg(argptr, int);
    if (num < 0)
    {
        specification->minus = 1;
        num = num * -1;
    }
    else
        specification->minus = 0;
    di_processor(specification, num);
    return (1);
}

int c_handler(p_struct *specification, va_list argptr)
{
    char symbol;

    if (specification->type == 'c')
        symbol = va_arg(argptr, int);
    else
        symbol = '%';
    c_processor(specification, symbol);
    return (1);
}

int p_handler(p_struct *specification, va_list argptr)
{
    unsigned long int *ptr;

    ptr = va_arg(argptr, void*);
	p_processor(specification, (unsigned long int)ptr);
    return (1);
}

int uxX_handler(p_struct *specification, va_list argptr)
{
    unsigned int unum;

    unum = va_arg(argptr, unsigned int);
    if (specification->type == 'u')
	    u_processor(specification, unum);
    else if (specification->type == 'x' || specification->type == 'X')
        xX_processor(specification, unum);
    return (1);
}