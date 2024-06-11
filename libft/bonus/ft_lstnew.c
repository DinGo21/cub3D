/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:44:28 by disantam          #+#    #+#             */
/*   Updated: 2024/05/30 10:50:14 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
	{
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}
