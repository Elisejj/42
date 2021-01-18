/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:41:00 by lmeribal          #+#    #+#             */
/*   Updated: 2021/01/15 19:51:40 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (big == little)
		return ((char *)big);
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (big[i + j] == little[j] && i + j < len && little[j] != '\0')
			{
				j++;
				if (little[j] == '\0')
					return ((char*)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
