/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:33:15 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/14 21:20:17 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	if (num == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (num < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(num * (-1), fd);
	}
	else if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(num + '0', fd);
	}
}
