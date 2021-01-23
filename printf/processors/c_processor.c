/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_processor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:43:29 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/21 19:43:26 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_if_neg_value(p_struct *specification, char symbol)
{
    specification->width *= -1;
    ft_putchar_fd(symbol, 1);
    specification->length++;
    while (specification->width - 1 > 0)
    {
        specification->length++;
        ft_putchar_fd(' ', 1);
        specification->width--;
    }
}

static void put_if_flags(p_struct *specification, char symbol)
{
    if (specification->flags == '-' || specification->flags == '\0')
    {
        if (specification->flags == '-')
            ft_putchar_fd(symbol, 1);
        while (specification->width - 1 > 0)
        {
            specification->length++;
            ft_putchar_fd(' ', 1);
            specification->width--;
        }
        if (specification->flags == '\0')
            ft_putchar_fd(symbol, 1);
        specification->length++;
    }
    else if (specification->flags == '0' && symbol == '%')
    {
        while (specification->width - 1 > 0)
        {
            specification->length++;
            ft_putchar_fd('0', 1);
            specification->width--;
        }
        ft_putchar_fd(symbol, 1);
        specification->length++;
    }
}

int c_processor(p_struct *specification, char symbol)
{
    if (specification->width < 0)
        put_if_neg_value(specification, symbol);
    else
        put_if_flags(specification, symbol);
    return (1);
}