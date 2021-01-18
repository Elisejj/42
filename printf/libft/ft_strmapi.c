/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:39:16 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/17 21:26:47 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, int (f)(char))
{
	char	*res;
	int		s_len;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	res = (char*)malloc((s_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < s_len)
	{
		res[i] = f(s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
