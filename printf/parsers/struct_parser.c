/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:07:24 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/18 21:16:57 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_between_specificators(const char *s, size_t *print_length)
{
	int index;

	index = 0;
	if (s)
	{
		while (s[index] != '%' && s[index] != '\0')
		{
			ft_putchar_fd(s[index], 1);
			(*print_length)++;
			index++;
		}
	}
}

int digit_parser(const char **s)
{
	int num_len;
	const char *tmp_str;

	tmp_str = *s;
	num_len = 0;
	while (ft_isdigit(tmp_str[num_len]))
	{
		num_len++;
		(*s)++;
	}
	return (ft_atoi(ft_substr(tmp_str, 0, num_len)));
}

p_struct specification_parser(const char **s, va_list argptr)
{
	p_struct specification;

	specification.flags = '\0';
	specification.plus = 0;
	specification.minus = 0;
	specification.width = 0;
	specification.precision = 0;
	specification.space = 0;
	specification.dot = 0;

	(*s)++;
	if (**s == ' ')
	{
		specification.space = 1;
		while (**s == ' ')
			(*s)++;
	}
	if (**s == '-' || **s == '0')
	{
		while (**s == '-' || **s == '0')
		{
			if (specification.flags == '\0' || (specification.flags == '0' && **s == '-'))
				specification.flags = **s;
			(*s)++;
		}
	}
	if (**s == ' ')
	{
		specification.space = 1;
		while (**s == ' ')
			(*s)++;
	}
	else if (**s == '+')
	{
		specification.plus = 1;
		(*s)++;
	}
	if (**s == '-' || **s == '0')
	{
		while (**s == '-' || **s == '0')
		{
			if (specification.flags == '\0' || (specification.flags == '0' && **s == '-'))
				specification.flags = **s;
			(*s)++;
		}
	}
	if (**s == '*')
	{
		specification.width = va_arg(argptr, int);
		(*s)++;
	}
	else if (ft_isdigit(**s))
		specification.width = digit_parser(&(*s));
	if (**s == '.')
	{
		specification.dot = 1;
		(*s)++;
		if (**s == '*')
		{
			specification.precision = va_arg(argptr, int);
			(*s)++;
		}
		else if (ft_isdigit(**s))
			specification.precision = digit_parser(&(*s));
	}
	specification.type = **s;
	(*s)++;
	return (specification);
}

void struct_parser(const char *format, va_list argptr, int args_count, size_t *print_length)
{
	const char *ptr_to_flag;
	p_struct specification;
	char symbol;
	char *string;
	signed int num;
	void *ptr;
	unsigned int unum;

	ptr_to_flag = ft_strchr(format, '%');
	while (args_count && ptr_to_flag)
	{   
		specification = specification_parser(&ptr_to_flag, argptr);

		if (specification.type == 's')
		{
			string = va_arg(argptr, char*);
			if (!string)
				string = "(null)";
			specification.length = ft_strlen(string);
			s_processor(specification, string, &(*print_length));
		}
		else if (specification.type == 'c' || specification.type == '%')
		{
			if (specification.type == 'c')
				symbol = va_arg(argptr, int);
			else
				symbol = '%';
			c_processor(specification, symbol, &(*print_length));
		}
		else if (specification.type == 'p')
		{
			ptr = va_arg(argptr, void*);

			p_processor(specification, (uintptr_t)ptr, &(*print_length));
		}
		else if (specification.type == 'd' || specification.type == 'i')
		{
			num = va_arg(argptr, int);
			if (num < 0)
			{
				specification.minus = 1;
				num = num * -1;
			}
			else
				specification.minus = 0;
			di_processor(specification, num, &(*print_length));
		}       
		else if (specification.type == 'u')
		{
			unum = va_arg(argptr, unsigned int);
			u_processor(specification, unum, &(*print_length));
		}
		else if (specification.type == 'x' || specification.type == 'X')
		{
			unum = va_arg(argptr, unsigned int);
			xX_processor(specification, unum, &(*print_length));
		}
		print_between_specificators(ptr_to_flag, &(*print_length));
		ptr_to_flag = ft_strchr(ptr_to_flag, '%');
		args_count--;
	}
}
