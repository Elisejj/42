/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:07:24 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/22 18:20:05 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

p_struct specification_parser(const char **s, va_list argptr)
{
	p_struct specification;

	set_specifications(&specification, &(*s));
	check_spaces(&specification, &(*s));
	check_flags(&specification, &(*s));
	check_spaces(&specification, &(*s));
	check_flags(&specification, &(*s));
	if (**s == '*')
	{
		specification.width = va_arg(argptr, int);
		(*s)++;
	}
	else if (ft_isdigit(**s))
		specification.width = digit_parser(&(*s));
	check_precision(&specification, &(*s), argptr);
	specification.type = **s;
	(*s)++;
	return (specification);
}

size_t struct_parser(const char *format, va_list argptr, int args_count)
{
	const char *ptr_to_flag;
	p_struct specification;
	size_t print_length;
	int ret;

	print_length = 0;
	ptr_to_flag = ft_strchr(format, '%');
	while (args_count && ptr_to_flag)
	{   
		specification = specification_parser(&ptr_to_flag, argptr);
		if (specification.type == 's')
			ret = s_handler(&specification, argptr);
		else if (specification.type == 'c' || specification.type == '%')
			ret = c_handler(&specification, argptr);
		else if (specification.type == 'p')
			ret = p_handler(&specification, argptr);
		else if (specification.type == 'd' || specification.type == 'i')
			ret = di_handler(&specification, argptr);
		else if (specification.type == 'x' || specification.type == 'X' || specification.type == 'u')
			ret = uxX_handler(&specification, argptr);
		print_between_specificators(&specification, ptr_to_flag);
		ptr_to_flag = ft_strchr(ptr_to_flag, '%');
		args_count--;
		print_length += specification.length;
		if (ret == -1)
			return (-1);
	}
	return (print_length);
}
