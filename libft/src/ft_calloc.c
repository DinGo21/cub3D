/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:41:46 by disantam          #+#    #+#             */
/*   Updated: 2024/01/19 16:03:20 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	i = -1;
	while (++i < count * size)
	{
		((char *)ptr)[i] = 0;
	}
	return (ptr);
}
