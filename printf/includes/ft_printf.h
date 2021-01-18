/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:07:07 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/18 17:15:50 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../libft/libft.h"

typedef struct{
    char flags;
    int width;
    int precision;
    char type;
    int length;
    int plus;
    int minus;
    int space;
    int dot;
} p_struct;

int ft_printf(const char *format, ...);
int printf_parser(const char *format, va_list argptr);
void struct_parser(const char *format, va_list argptr, int args_count, size_t *print_length);
p_struct specification_parser(const char **s, va_list argptr);
int s_processor(p_struct specification, char *string, size_t *print_length);
int c_processor(p_struct specification, char symbol, size_t *print_length);
int di_processor(p_struct specification, int num, size_t *print_length);
int u_processor(p_struct specification, unsigned int num, size_t *print_length);
int ft_numlen(p_struct specification, int num);
void put_sign(p_struct specification);
int xX_processor(p_struct specification, unsigned int num, size_t *print_length);
int p_processor(p_struct specification, uintptr_t num, size_t *print_length);
int get_zero_len(p_struct specification, int number_len);
int get_num_len(p_struct specification, int num);
int get_space_len(p_struct specification, int number_len, int zero_len);

#endif 