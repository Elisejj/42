/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:27:26 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/21 19:40:51 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *hex_to_upper(char *hex_str)
{
	char *tmp;

	tmp = hex_str;
	while (*hex_str)
	{
		if (ft_isalpha(*hex_str))
			*hex_str = ft_toupper(*hex_str);
		hex_str++;
	}
	return (tmp);
}

static char *preprocess_hex_values(p_struct *specification, unsigned int *num, int *neg_width, int *zero_len, int *space_len)
{
	int number_len;
	char *num_16_base;
	
	*neg_width = 0;
	if (specification->width < 0)
		*neg_width = 1;
	num_16_base = ft_itoa_base(*num, 16);
	number_len = get_hex_len(specification, num_16_base, *num);
	if (specification->type == 'X')
		num_16_base = hex_to_upper(num_16_base);
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

int xX_processor(p_struct *specification, unsigned int num)
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