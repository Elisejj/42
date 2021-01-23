/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:14:27 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/22 18:13:48 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_between_specificators(p_struct *specification, const char *s)
{
	int index;

	index = 0;
	if (s)
	{
		while (s[index] != '%' && s[index] != '\0')
		{
			ft_putchar_fd(s[index], 1);
			specification->length++;
			index++;
		}
	}
}

int put_if_neg_width(p_struct *specification, long long int num, int space_len, int zero_len)
{
	int number_len;

	number_len = get_num_len(specification, num);
	if (specification->dot == 0 && specification->precision == 0)
		zero_len = 0;
	space_len = (specification->width * -1) - (number_len + zero_len);
	if (space_len < 0)
		space_len = 0;
	specification->length += space_len;
	specification->length += zero_len;
	specification->length += number_len;
	put_sign(specification);
	while (zero_len--)
		ft_putchar_fd('0', 1);
	if ((num != 0) || (num == 0 && specification->precision != 0) || (num == 0 && specification->precision == 0 && specification->dot != 1))
		ft_putnbr_fd(num, 1);
	while (space_len--)
		ft_putchar_fd(' ', 1);
	return (1);
}

int put_if_flag(p_struct *specification, long long int num, int space_len, int zero_len)
{
	if (specification->flags == '0' || specification->flags == '\0')
	{
		while (space_len--)
			ft_putchar_fd(' ', 1);
		put_sign(specification);
		while (zero_len--)
			ft_putchar_fd('0', 1);
		if ((num != 0) || (num == 0 && specification->precision != 0) || (num == 0 && specification->precision == 0 && specification->dot != 1))
		{
			ft_putnbr_fd(num, 1);
		}
	}
	else if (specification->flags == '-')
	{
		put_sign(specification);
		while (zero_len--)
			ft_putchar_fd('0', 1);
		if ((num != 0) || (num == 0 && specification->precision != 0) || (num == 0 && specification->precision == 0 && specification->dot != 1))
			ft_putnbr_fd(num, 1);
		while (space_len--)
			ft_putchar_fd(' ', 1);
	}
	return (1);
}

int put_if_neg_width_16_base(p_struct *specification, char *num_16_base, int zero_len, unsigned long int num)
{
	int number_len;
    int space_len;

	number_len = get_hex_len(specification, num_16_base, num);
	if (specification->dot == 0 && specification->precision == 0)
		zero_len = 0;
	space_len = (specification->width * -1) - (number_len + zero_len);
	if (space_len < 0)
		space_len = 0;
	specification->length += space_len;
	specification->length += zero_len;
	specification->length += number_len;
	put_sign(specification);
	while (zero_len--)
		ft_putchar_fd('0', 1);
	if ((num == 0 && specification->type == 'p') || (num != 0) || (num == 0 && specification->precision != 0) || (num == 0 && specification->precision == 0 && specification->dot != 1))
		ft_putstr_fd(num_16_base, 1);
	while (space_len--)
		ft_putchar_fd(' ', 1);
	if (!specification->dot)
			free(num_16_base);
	return (1);
}

int put_if_flag_16_base(p_struct *specification, char *num_16_base, int space_len, int zero_len, unsigned long int num)
{
	if (specification->flags == '0' || specification->flags == '\0')
	{
		while (space_len--)
			ft_putchar_fd(' ', 1);
		put_sign(specification);
		while (zero_len--)
			ft_putchar_fd('0', 1);
		if ((num == 0 && specification->type == 'p') ||(num != 0) || (num == 0 && specification->precision != 0) || (num == 0 && specification->precision == 0 && specification->dot != 1))
			ft_putstr_fd(num_16_base, 1);
	}
	else if (specification->flags == '-')
	{
		put_sign(specification);
		while (zero_len--)
			ft_putchar_fd('0', 1);
		if ((num == 0 && specification->type == 'p') || (num != 0) || (num == 0 && specification->precision != 0) || (num == 0 && specification->precision == 0 && specification->dot != 1))
			ft_putstr_fd(num_16_base, 1);
		while (space_len--)
			ft_putchar_fd(' ', 1);
	}
	if (num)
		free(num_16_base);
	return (1);
}