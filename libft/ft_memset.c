/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:18:17 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/14 21:18:51 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int ch, size_t n)
{
	size_t				i;
	unsigned	char	*c;

	c = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		c[i] = ch;
		i++;
	}
	return ((void*)c);
}
