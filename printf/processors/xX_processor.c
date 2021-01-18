/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:27:26 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/18 21:27:31 by lmeribal         ###   ########.fr       */
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

static int get_hex_len(p_struct specification, char *hex_num)
{
	int number_len;

	number_len = ft_strlen(hex_num);
	if (specification.dot == 1 && specification.precision == 0)
		number_len = 0; 
	return (number_len);
}  

static char *preprocess_hex_values(p_struct specification, unsigned int *num, int *zero_len, int *space_len)
{
	int number_len;
	char *num_16_base;

	num_16_base = ft_itoa_base(*num, 16);
	number_len = get_hex_len(specification, num_16_base);
	if (specification.type == 'X')
		num_16_base = hex_to_upper(num_16_base);
	*zero_len = get_zero_len(specification, number_len);
	*space_len = get_space_len(specification, number_len, *zero_len);
	if (specification.precision <= 0 && specification.flags == '0' && specification.dot != 1)
	{
		*zero_len = specification.width - number_len;
		if (*zero_len < 0)
			*zero_len = 0;
		*space_len = 0;
	}
	return (num_16_base);
}

static int put_if_flag(p_struct specification, char *num_16_base, int space_len, int zero_len, unsigned int num)
{
	if (specification.flags == '0' || specification.flags == '\0')
	{
		while (space_len--)
			ft_putchar_fd(' ', 1);
		put_sign(specification);
		while (zero_len--)
			ft_putchar_fd('0', 1);
		if ((num != 0) || (num == 0 && specification.precision != 0) || (num == 0 && specification.precision == 0 && specification.dot != 1))
			ft_putstr_fd(num_16_base, 1);
	}
	else if (specification.flags == '-')
	{
		put_sign(specification);
		while (zero_len--)
			ft_putchar_fd('0', 1);
		if ((num != 0) || (num == 0 && specification.precision != 0) || (num == 0 && specification.precision == 0 && specification.dot != 1))
			ft_putstr_fd(num_16_base, 1);
		while (space_len--)
			ft_putchar_fd(' ', 1);
	}
	return (1);
}

int xX_processor(p_struct specification, unsigned int num, size_t *print_length)
{
	int zero_len;
	int space_len;
	char *num_16_base;
	
	num_16_base = preprocess_hex_values(specification, &num, &zero_len, &space_len);
	if (specification.space == 1 && specification.plus != 1 && specification.minus != 1)
	{
		ft_putchar_fd(' ', 1);
		if (space_len > 0)
			space_len--;
	}
	*print_length += zero_len;
	*print_length += space_len;
	*print_length += get_hex_len(specification, num_16_base);
	put_if_flag(specification, num_16_base, space_len, zero_len, num);
	return (1);
}