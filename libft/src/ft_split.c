/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:20:53 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/14 22:04:12 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		word_count(char const *s, char c)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

static	int		word_len(const char *s, char c)
{
	int len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static	void	leak(char **s, int i)
{
	while (i > 0)
	{
		free(s[i]);
		s[i] = NULL;
		i--;
	}
	free(s);
	s = NULL;
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	i = -1;
	j = 0;
	if (!s || !(res = (char**)malloc((word_count(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while (++i < word_count(s, c))
	{
		while (s[j] == c)
			j++;
		k = j;
		if (!(res[i] = (char*)malloc(sizeof(char) * (word_len(&s[j], c) + 1))))
		{
			leak(res, j);
			return (NULL);
		}
		while (s[j] != c && s[j] != '\0')
			j++;
		res[i] = ft_substr(s, k, j - k);
	}
	res[i] = NULL;
	return (res);
}
