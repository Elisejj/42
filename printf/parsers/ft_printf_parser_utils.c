#include "ft_printf.h"

int digit_parser(const char **s)
{
	int num_len;
	const char *tmp_str_1;
	char *tmp_str_2;
	int result;

	tmp_str_1 = *s;
	num_len = 0;
	while (ft_isdigit(tmp_str_1[num_len]))
	{
		num_len++;
		(*s)++;
	}
	if (!(tmp_str_2 = ft_substr(tmp_str_1, 0, num_len)))
		reutrn (-1);
	result = ft_atoi(tmp_str_2);
	free(tmp_str_2);
	return (result);
}

void set_specifications(p_struct *specification, const char **s)
{
	specification->flags = '\0';
	specification->plus = 0;
	specification->minus = 0;
	specification->width = 0;
	specification->precision = 0;
	specification->space = 0;
	specification->dot = 0;
	specification->leak = 0;
	specification->length = 0;
	(*s)++;
}

void check_flags(p_struct *specification, const char **s)
{
	if (**s == '-' || **s == '0')
	{
		while (**s == '-' || **s == '0')
		{
			if (specification->flags == '\0' ||
					(specification->flags == '0' && **s == '-'))
				specification->flags = **s;
			(*s)++;
		}
	}
}

void check_precision(p_struct *specification, const char **s, va_list argptr)
{
	if (**s == '.')
	{
		specification->dot = 1;
		(*s)++;
		if (**s == '*')
		{
			specification->precision = va_arg(argptr, int);
			(*s)++;
		}
		else if (ft_isdigit(**s))
			specification->precision = digit_parser(&(*s));
	}
	if (specification->precision < 0)
	{
		specification->dot = 0;
		specification->precision = 0;
	}
}

void check_spaces(p_struct *specification, const char **s)
{
	if (**s == ' ')
	{
		specification->space = 1;
		while (**s == ' ')
			(*s)++;
	}
	else if (**s == '+')
	{
		specification->plus = 1;
		(*s)++;
	}
}