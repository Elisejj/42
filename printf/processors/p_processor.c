/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_processor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:51:36 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/21 20:52:33 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *preprocess_hex_values(p_struct *specification, unsigned long int *num, int *neg_width, int *zero_len, int *space_len)
{
	int number_len;
	char *num_16_base;
	char *prefix;
	char *tmp;
	*neg_width = 0;
	
	if (specification->width < 0)
		*neg_width = 1;
	prefix = "0x";
	num_16_base = ft_itoa_base(*num, 16);
	tmp = num_16_base;
	num_16_base = ft_strjoin(prefix, num_16_base);
	free(tmp);
	if (!(ft_strncmp(num_16_base, "0x0", 3)) && specification->dot == 1)
		num_16_base = prefix;
	number_len = get_hex_len(specification, num_16_base, *num);
	*zero_len = get_zero_len(specification, number_len);
	*space_len = get_space_len(specification, number_len, *zero_len);
	if (specification->precision <= 0 && specification->flags == '0' && specification->dot != 1)
	{
		*zero_len = specification->width - number_len;
		if (*zero_len < 0)
			*zero_len = 0;
		*space_len = 0;
	}
	return (num_16_base);
}

int p_processor(p_struct *specification, uintptr_t num)
{
	int zero_len;
	int space_len;
	char *num_16_base;
	int neg_width;
	
	num_16_base = preprocess_hex_values(specification, &num, &neg_width, &zero_len, &space_len);
	if (specification->space == 1 && specification->plus != 1 && specification->minus != 1)
	{
		ft_putchar_fd(' ', 1);
		if (space_len > 0)
			space_len--;
	}
	if (!neg_width)
	{
		specification->length += zero_len;
		specification->length += space_len;
		specification->length += get_hex_len(specification, num_16_base, num);
	}
	if (neg_width)
		put_if_neg_width_16_base(specification, num_16_base, zero_len, num);
	else
		put_if_flag_16_base(specification, num_16_base, space_len, zero_len, num);
	return (1);
}
