/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:39:06 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/14 21:02:07 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			get_length(int num)
{
	int len;

	len = 0;
	if (num < 0)
	{
		len++;
		num = num * (-1);
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static	char		*check_num(int num, char *str)
{
	if (num == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	if (num == 0)
	{
		str[0] = 48;
		return (str);
	}
	return (NULL);
}

char				*ft_itoa(int num)
{
	char	*str;
	char	*res;
	int		i;

	i = get_length(num);
	if (!(str = (char*)malloc(((1 + i) * sizeof(char)))))
		return (NULL);
	if ((res = check_num(num, str)))
		return (res);
	str[i--] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = num * (-1);
	}
	while (num > 0)
	{
		str[i--] = 48 + (num % 10);
		num = num / 10;
	}
	return (str);
}
