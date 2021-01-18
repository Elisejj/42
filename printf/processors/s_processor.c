/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_processor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:13:01 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/18 17:44:25 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *preprocess_values(p_struct specification, char **string, int *neg_width, int *string_len)
{
    char *cutted_string;

    *neg_width = 0;
    if (ft_strlen(*string) > (size_t)specification.precision && specification.precision != 0)
        cutted_string = ft_substr(*string, 0, specification.precision);
    else
        cutted_string = *string;
    *string_len = ft_strlen(cutted_string);
    if (specification.dot == 1 && specification.precision <= 0 && specification.width >= 0)
        *string_len = 0;
    return (cutted_string);
}

int s_processor(p_struct specification, char *string, size_t *print_length)
{
    char *cutted_string;
    int string_len;
    int neg_width;

    cutted_string = preprocess_values(specification, &string, &neg_width, &string_len);
    if ((specification.flags == '-' && (!(specification.precision == 0 && specification.dot == 1) || (specification.precision == 0 && specification.dot == 0))) || specification.width < 0)
    {
        ft_putstr_fd(cutted_string, 1);
        if (specification.width < 0)
        {
            specification.width = specification.width * -1;
            neg_width = 1;
        }
    }
    while (specification.width - string_len > 0)
    {
        if (specification.flags != '0')
            ft_putchar_fd(' ', 1);
        else 
            ft_putchar_fd('0', 1);
        (*print_length)++;
        specification.width--;
    }
    if (neg_width != 1 && specification.flags != '-' && (!(specification.precision == 0 && specification.dot == 1) || (specification.precision == 0 && specification.dot == 0)))
        ft_putstr_fd(cutted_string, 1);

    if (!(specification.dot == 1 && specification.precision == 0))
        *print_length = *print_length + ft_strlen(cutted_string);
    return (1);
}