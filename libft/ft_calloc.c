/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:12:13 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/14 20:16:37 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elem_count, size_t elem_size)
{
	void *arr;

	arr = malloc(elem_count * elem_size);
	if (arr)
		ft_memset(arr, 0, elem_count * elem_size);
	return (arr);
}
