/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:23:54 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/03 17:30:05 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

char *ft_memset(char *arr, int c, int n);

int ft_atoi(char *str);

int ft_isalnum(int c);

int ft_isalpha(int c);

int ft_isascii(int c);

int ft_isdigit(int num);

int ft_isprint(int c);

char *ft_memccpy(char *arr, char *source, int c, int n);

char *ft_strchr(char *str, int n);

int ft_strlen(char *str);

int ft_strncmp(void *s1, void *s2, int n);

char *ft_strrchr(char *str, int n);

int ft_tolower(int c);

char ft_toupper(int c);

char *ft_strnstr(char *big, char *little, int len);

char *ft_memchr(void *s, int c, int n);

int ft_memcmp(void *s1, void *s2, int n);

char *ft_memcpy(char* dest, char* source, int n);

int ft_strlcpy(char* dest, char* src, int n);

int ft_strlcat(char* dest, char* src, int n);

#endif