/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:53:00 by disantam          #+#    #+#             */
/*   Updated: 2024/05/30 10:49:28 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	while (*lst != NULL)
	{
		node = *lst;
		*lst = node->next;
		del(node->content);
		free(node);
	}
	lst = NULL;
}
