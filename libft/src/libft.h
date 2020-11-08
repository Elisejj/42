#ifndef LIBFT_H

# define LIBFT_H

#include <stdlib.h>

void *ft_memset(void *s, int ch, size_t n);

int ft_atoi(const char *str);

int ft_isalnum(int c);

int ft_isalpha(int c);

int ft_isascii(int c);

int ft_isdigit(int num);

int ft_isprint(int c);

void *ft_memccpy(void *dest, const void *source, int c, size_t n);

char *ft_strchr(const char *str, int n);

size_t ft_strlen(const char *str);

int ft_strncmp(const char *s1, const char *s2, size_t n);

char *ft_strrchr(const char *str, int n);

int ft_tolower(int c);

char ft_toupper(int c);

char* ft_strnstr(const char *big, const char *little, size_t len);

void *ft_memchr(const void *s, int c, size_t n);

void* ft_memcpy(void* dest, const void* source, size_t n);

size_t ft_strlcpy(char* dest, char* src, size_t n);

size_t ft_strlcat(char* dest, const char* src, size_t n);

void ft_bzero(void *s, size_t n);

void *ft_calloc(size_t elem_count, size_t elem_size);

char *ft_strdup(char *str);

void *ft_memmove(void *dest, void *src, size_t n);

void ft_putchar_fd(char c, int fd);

void ft_putstr_fd(char *str, int fd);

void ft_putnbr_fd(int num, int fd);

char *ft_substr(char const *s, int start, int len);

char *ft_strjoin(char const *s1, char const *s2);

char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

void ft_putendl_fd(char *s, int fd);

char *ft_itoa(int num);

char *ft_strtrim(char const *s1, char const *set);

#endif