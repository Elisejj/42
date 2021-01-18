/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:06:39 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/14 21:07:00 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	size_t				i;
	unsigned	char	ch;
	unsigned	char	*uc_dest;
	unsigned	char	*uc_src;

	ch = (unsigned char)c;
	uc_dest = (unsigned char *)dest;
	uc_src = (unsigned char *)source;
	i = 0;
	while (i < n && (i == 0 || uc_src[i - 1] != ch))
	{
		uc_dest[i] = uc_src[i];
		i += 1;
	}
	if (i > 0 && uc_src[i - 1] == ch)
		return (void*)(uc_dest + i);
	else
		return (NULL);
}
