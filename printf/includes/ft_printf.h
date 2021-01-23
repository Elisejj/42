/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:07:07 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/22 16:55:45 by lmeribal         ###   ########.fr       */
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
    int plus;
    int minus;
    int space;
    int dot;
    int leak;
    size_t length;
} p_struct;

int ft_printf(const char *format, ...);
void ft_leak_checker(p_struct *specification, void *obj);
int s_handler(p_struct *specification, va_list argptr);
int di_handler(p_struct *specification, va_list argptr);
int c_handler(p_struct *specification, va_list argptr);
int uxX_handler(p_struct *specification, va_list argptr);
int p_handler(p_struct *specification, va_list argptr);
int printf_parser(const char *format, va_list argptr);
int digit_parser(const char **s);
void set_specifications(p_struct *specification, const char **s);
void check_flags(p_struct *specification, const char **s);
void check_precision(p_struct *specification, const char **s, va_list argptr);
void check_spaces(p_struct *specification, const char **s);
size_t struct_parser(const char *format, va_list argptr, int args_count);
void print_between_specificators(p_struct *specification, const char *s);
p_struct specification_parser(const char **s, va_list argptr);
int s_processor(p_struct *specification, char *string);
int c_processor(p_struct *specification, char symbol);
int di_processor(p_struct *specification, int num);
int u_processor(p_struct *specification, unsigned int num);
int ft_numlen(p_struct *specification, int num);
void put_sign(p_struct *specification);
int xX_processor(p_struct *specification, unsigned int num);
int p_processor(p_struct *specification, uintptr_t num);
int get_zero_len(p_struct *specification, int number_len);
int get_num_len(p_struct *specification, long long int num);
int get_space_len(p_struct *specification, int number_len, int zero_len);
int put_if_neg_width(p_struct *specification, long long int num, int space_len, int zero_len);
int put_if_flag(p_struct *specification, long long int num, int space_len, int zero_len);
int put_if_flag_16_base(p_struct *specification, char *num_16_base, int space_len, int zero_len, unsigned long int num);
int put_if_neg_width_16_base(p_struct *specification, char *num_16_base, int zero_len, unsigned long int num);
int get_hex_len(p_struct *specification, char *hex_num, unsigned int num);

#endif 