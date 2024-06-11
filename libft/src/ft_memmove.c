/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:48:50 by disantam          #+#    #+#             */
/*   Updated: 2024/01/17 12:07:44 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dststr;
	char	*srcstr;

	if (dst == 0 && src == 0)
		return (NULL);
	i = 0;
	dststr = dst;
	srcstr = (char *)src;
	if (dst > src)
	{
		while (len-- > 0)
		{
			dststr[len] = srcstr[len];
		}
	}
	else
	{
		while (i < len)
		{
			dststr[i] = srcstr[i];
			i++;
		}
	}
	return (dststr);
}
