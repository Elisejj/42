/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:09:59 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/14 21:18:08 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t				i;
	unsigned	char	*c1;
	unsigned	char	*c2;

	c1 = (unsigned char*)dest;
	c2 = (unsigned char*)src;
	if (n && (src || dest))
	{
		if (src < dest)
		{
			i = n;
			while (i--)
				c1[i] = c2[i];
		}
		else
		{
			i = 0;
			while (i < n)
			{
				c1[i] = c2[i];
				i++;
			}
		}
	}
	return ((void*)c1);
}
