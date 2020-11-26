#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *str);
char	*ft_strchr(const char *str, int n);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int ch, size_t n);
char	*ft_strcpy(char *dest, char *src);
void ft_strclr(char *str);


# endif