/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:04 by disantam          #+#    #+#             */
/*   Updated: 2024/05/30 10:49:20 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
