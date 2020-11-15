/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:41:35 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/14 21:41:48 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	char *res;

	res = (char *)str + ft_strlen(str);
	while (*res != n)
	{
		if (res == str)
			return (NULL);
		res--;
	}
	return (res);
}
