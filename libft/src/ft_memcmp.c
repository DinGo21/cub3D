/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:07:51 by disantam          #+#    #+#             */
/*   Updated: 2024/01/17 12:01:26 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (n == 0)
		return (0);
	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n - 1)
	{
		if (ptr1[i] != ptr2[i])
		{
			return (ptr1[i] - ptr2[i]);
		}
		i++;
	}
	if (i < n && ptr1[i] != ptr2[i])
	{
		return (ptr1[i] - ptr2[i]);
	}
	return (0);
}
