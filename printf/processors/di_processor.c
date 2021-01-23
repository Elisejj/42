/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:19:25 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/21 19:37:15 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void preprocess_digit_values(p_struct *specification, int *num, int *neg_width, int *zero_len, int *space_len)
{
	int number_len;

	number_len = get_num_len(specification, *num);
	*neg_width = 0;
	*zero_len = get_zero_len(specification, number_len);
	if (specification->width < 0)
		*neg_width = 1;
	*space_len = get_space_len(specification, number_len, *zero_len);
	if (specification->precision <= 0 && specification->flags == '0' && specification->dot != 1)
	{
		*zero_len = specification->width - number_len;
		*space_len = 0;
	}
	if (*zero_len < 0)
		*zero_len = 0;
}

int di_processor(p_struct *specification, int num)
{
	int zero_len;
	int space_len;
	int neg_width;

	preprocess_digit_values(specification, &num, &neg_width, &zero_len, &space_len);
	if (!neg_width)
	{
		specification->length += zero_len;
		specification->length += space_len;
		specification->length += get_num_len(specification, num);
	}
	if (specification->space == 1 && specification->plus != 1 && specification->minus != 1)
	{
		ft_putchar_fd(' ', 1);
		if (space_len > 0)
			space_len--;
	}
	if (neg_width)
		put_if_neg_width(specification, num, space_len, zero_len);
	else
		put_if_flag(specification, num, space_len, zero_len);

	return (1);
}
