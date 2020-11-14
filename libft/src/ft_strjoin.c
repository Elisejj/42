/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:35:10 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/14 22:01:54 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	res = (char*)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
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
