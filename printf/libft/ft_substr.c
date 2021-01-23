/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:42:34 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/22 18:15:06 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(res = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (s)
	{
		while (s[start] && i < len)
		{
			res[i] = s[start];
			i++;
			start++;
		}
		res[i] = '\0';
	}
	return (res);
}
