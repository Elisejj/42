#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}



char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = -1;
	j = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(res = (char*)malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (NULL);
	while (++i < s1_len)
	{
		res[i] = s1[i];
	}
	while (++j < s2_len)
	{
		res[i] = s2[j];
		i++;
	}
	res[i] = '\0';
	return (res);
}


char	*ft_strdup(char *str)
{
	int		str_len;
	char	*res;
	int		i;

	i = 0;
	str_len = ft_strlen(str);
	res = (char*)malloc((str_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}


char	*ft_strchr(const char *str, int n)
{
	while (*str != n)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strcpy(char *dest, char *src)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!dest || !src)
		return (0);
	if ((dest || src))
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

void ft_strclr(char *str)
{
	if (str)
		while (*str)
		{
			*str = '\0';
			str++;
		}
}