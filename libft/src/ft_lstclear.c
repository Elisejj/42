/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:03:28 by lmeribal          #+#    #+#             */
/*   Updated: 2020/11/14 21:03:35 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *entry;

	entry = *lst;
	while (entry)
	{
		tmp = entry->next;
		ft_lstdelone(entry, del);
		entry = tmp;
	}
	*lst = NULL;
}
