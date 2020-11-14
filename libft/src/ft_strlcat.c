/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:37:39 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/14 21:38:12 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t count_dest;
	size_t count_src;

	i = 0;
	count_dest = 0;
	count_src = 0;
	while (src[count_src] != '\0')
		count_src++;
	if (n == 0)
		return (count_src);
	while (count_dest < n && dest[count_dest] != '\0')
		count_dest++;
	if (n <= count_dest)
		return (n + count_src);
	while (n != 0 && (--n - count_dest != 0) && src[i] != '\0')
	{
		dest[count_dest + i] = src[i];
		i++;
	}
	dest[count_dest + i] = '\0';
	return (count_dest + count_src);
}
