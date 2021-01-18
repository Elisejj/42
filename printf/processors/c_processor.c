/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_processor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:43:29 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/18 17:10:10 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int c_processor(p_struct specification, char symbol, size_t *print_length)
{
    if (specification.flags == '-' || specification.flags == '\0')
    {
        if (specification.flags == '-')
            ft_putchar_fd(symbol, 1);
        while (specification.width - 1 > 0)
        {
            (*print_length)++;
            ft_putchar_fd(' ', 1);
            specification.width--;
        }
        if (specification.flags == '\0')
            ft_putchar_fd(symbol, 1);
        (*print_length)++;
    }
    else if (specification.flags == '0' && symbol == '%')
    {
        while (specification.width - 1 > 0)
        {
            (*print_length)++;
            ft_putchar_fd('0', 1);
            specification.width--;
        }
        ft_putchar_fd(symbol, 1);
        (*print_length)++;
    }
    return (1);
}