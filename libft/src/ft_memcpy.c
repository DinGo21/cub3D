/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:32:57 by disantam          #+#    #+#             */
/*   Updated: 2024/01/17 11:53:40 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dststr;
	char	*srcstr;

	if (dst == 0 && src == 0)
	{
		return (NULL);
	}
	i = 0;
	dststr = dst;
	srcstr = (char *)src;
	while (i < n)
	{
		dststr[i] = srcstr[i];
		i++;
	}
	return (dststr);
}
