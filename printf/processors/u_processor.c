#include "ft_printf.h"

static int get_unum_len(p_struct specification, unsigned int num)
{
	int len;

	len = 0;
	if (num == 0)
		len = 1;
	if (specification.minus == 1)
		len++;
	else if (specification.plus == 1)
		len++;
	while (num)
	{
		num = num / 10;
		len++;
	}
	if (specification.dot == 1 && specification.precision == 0)
		len = 0;
	return (len);
}

static int put_if_neg_width(p_struct specification, unsigned int num, int space_len, int zero_len)
{
	int number_len;

	number_len = get_num_len(specification, num);
	if (specification.dot == 0 && specification.precision == 0)
		zero_len = 0;
	space_len = specification.width - (number_len + zero_len);
	if (space_len < 0)
		space_len = 0;
	put_sign(specification);
	while (zero_len--)
		ft_putchar_fd('0', 1);
	if ((num != 0) || (num == 0 && specification.precision != 0) || (num == 0 && specification.precision == 0 && specification.dot != 1))
		ft_putnbr_fd(num, 1);
	while (space_len--)
		ft_putchar_fd(' ', 1);
	return (1);
}

static int put_if_flag(p_struct specification, unsigned int num, int space_len, int zero_len)
{
	if (specification.flags == '0' || specification.flags == '\0')
	{
		while (space_len--)
			ft_putchar_fd(' ', 1);
		put_sign(specification);
		while (zero_len--)
			ft_putchar_fd('0', 1);
		if ((num != 0) || (num == 0 && specification.precision != 0) || (num == 0 && specification.precision == 0 && specification.dot != 1))
			ft_putnbr_fd(num, 1);
	}
	else if (specification.flags == '-')
	{
		put_sign(specification);
		while (zero_len--)
			ft_putchar_fd('0', 1);
		if ((num != 0) || (num == 0 && specification.precision != 0) || (num == 0 && specification.precision == 0 && specification.dot != 1))
			ft_putnbr_fd(num, 1);
		while (space_len--)
			ft_putchar_fd(' ', 1);
	}
	return (1);
}

static void preprocess_digit_values(p_struct specification, unsigned int *num, int *neg_width, int *zero_len, int *space_len)
{
	int number_len;

	number_len = get_unum_len(specification, *num);
	*neg_width = 0;
	*zero_len = get_zero_len(specification, number_len);
	if (specification.width < 0)
	{
		specification.width = specification.width * -1;
		*neg_width = 1;
	}
	*space_len = get_space_len(specification, number_len, *zero_len);
	if (specification.precision <= 0 && specification.flags == '0' && specification.dot != 1)
	{
		*zero_len = specification.width - number_len;
		*space_len = 0;
	}
	if (*zero_len < 0)
		*zero_len = 0;
}

int u_processor(p_struct specification, unsigned int num, size_t *print_length)
{
	int zero_len;
	int space_len;
	int neg_width;

	preprocess_digit_values(specification, &num, &neg_width, &zero_len, &space_len);
	*print_length += zero_len;
	*print_length += space_len;
	*print_length += get_unum_len(specification, num);
	if (specification.space == 1 && specification.plus != 1 && specification.minus != 1)
	{
		ft_putchar_fd(' ', 1);
		if (space_len > 0)
			space_len--;
	}
	if (neg_width == 1)
		put_if_neg_width(specification, num, space_len, zero_len);
	else
		put_if_flag(specification, num, space_len, zero_len);
	return (1);
}