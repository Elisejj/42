/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:11:23 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/18 16:54:12 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printf_parser(const char *format, va_list argptr)
{
    int args_count;
    int first_flag_index;
    char *ptr_to_flag;
    char *str_first_part;
    size_t print_length;

    print_length = 0;
    args_count = 0;
    first_flag_index = 0;
    ptr_to_flag = ft_strchr(format, '%');

    // Если есть проценты
    if (ptr_to_flag)
    {
        while (format[first_flag_index] != '%')
            first_flag_index++;
        while (ptr_to_flag)
        {
            args_count++;
            ptr_to_flag++;
            ptr_to_flag = ft_strchr(ptr_to_flag, '%');
        }
    }
    else // иначе просто вернули строку и длину
    {
        ft_putstr_fd((char *)format, 1);
        return ft_strlen(format);
    }

    if (args_count > 0)
    {
        if (!(str_first_part = ft_substr(format, 0, first_flag_index)))
            return (-1);
        ft_putstr_fd(str_first_part, 1);
        print_length += ft_strlen(str_first_part);
        struct_parser(format, argptr, args_count, &print_length);
    }
    return (print_length);
}

int ft_printf(const char *format, ...)
{
    va_list argptr;
    size_t length;

    va_start(argptr, format);

    length = printf_parser(format, argptr);
    
    va_end(argptr);
    return (length);
}

